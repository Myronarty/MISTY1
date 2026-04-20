#include "Cipher_funcs.h"

uint64_t EncryptBlock(uint64_t P, uint16_t(&KL)[10][2], uint16_t(&KO)[8][4], uint16_t(&KI)[8][3])
{
	uint32_t L = uint32_t(P >> 32);
	uint32_t R = uint32_t(P);

	uint32_t L_prev = L;
	uint32_t R_prev = R;

	uint32_t L_curr = 0, R_curr = 0, L_next = 0, R_next = 0;

	for (int i = 0; i < 8; i += 2)
	{
		R_curr = FL(L_prev, KL[i]);
		L_curr = FL(R_prev, KL[i + 1]) ^ FO(R_curr, KO[i], KI[i]);

		L_next = R_curr ^ FO(L_curr, KO[i + 1], KI[i + 1]);
		R_next = L_curr;

		L_prev = L_next;
		R_prev = R_next;
	}

	uint32_t R_final = FL(L_prev, KL[8]);
	uint32_t L_final = FL(R_prev, KL[9]);

	uint64_t C = ((uint64_t)L_final << 32) | (uint64_t)R_final;

	return C;
}

uint64_t DecryptBlock(uint64_t C, uint16_t(&KL)[10][2], uint16_t(&KO)[8][4], uint16_t(&KI)[8][3])
{
	uint32_t L = uint32_t(C >> 32);
	uint32_t R = uint32_t(C);

	uint32_t L_prev = L;
	uint32_t R_prev = R;

	uint32_t L_curr = 0, R_curr = 0, L_next = 0, R_next = 0;

	for (int i = 9; i > 1; i -= 2)
	{
		R_curr = FL_1(L_prev, KL[i]);
		L_curr = FL_1(R_prev, KL[i - 1]) ^ FO(R_curr, KO[i - 2], KI[i - 2]);
		
		L_next = R_curr ^ FO(L_curr, KO[i - 3], KI[i - 3]);
		R_next = L_curr;

		L_prev = L_next;
		R_prev = R_next;
	}

	uint32_t R_final = FL_1(L_prev, KL[1]);
	uint32_t L_final = FL_1(R_prev, KL[0]);

	uint64_t P = ((uint64_t)L_final << 32) | (uint64_t)R_final;

	return P;
}

void MISTY1(string file_name, string out_name, string file_k)
{
	uint16_t K[8] = { 0 };
	getK(file_k, K);

	uint16_t KI[8][3] = { 0 };
	uint16_t KO[8][4] = { 0 };
	uint16_t KL[10][2]= { 0 };

	Expansion(K, KI, KO, KL);

	ifstream file(file_name, ios::binary);
	ofstream outputFile(out_name, ios::binary);

	if (!file || !outputFile)
	{
		cerr << "Womp womp, no such file" << endl;
		return;
	}

	uint64_t P = 0;

	while (file.read(reinterpret_cast<char*>(&P), sizeof(P)))
	{
		uint64_t C = EncryptBlock(P, KL, KO, KI);

		outputFile.write(reinterpret_cast<char*>(&C), sizeof(C));

		P = 0;
	}

	int bytes = file.gcount();

	if (bytes > 0)
	{
		char* p_bytes = reinterpret_cast<char*>(&P);
		for (int i = bytes; i < 8; i++)
		{
			p_bytes[i] = 0x00;
		}

		uint64_t C = EncryptBlock(P, KL, KO, KI);
		outputFile.write(reinterpret_cast<char*>(&C), sizeof(C));
	}

	file.close();
	outputFile.close();
}

void deMISTY1(string file_name, string out_name, string file_k)
{
	uint16_t K[8] = { 0 };
	getK(file_k, K);

	uint16_t KI[8][3] = { 0 };
	uint16_t KO[8][4] = { 0 };
	uint16_t KL[10][2] = { 0 };

	Expansion(K, KI, KO, KL);

	ifstream file(file_name, ios::binary);
	ofstream outputFile(out_name, ios::binary);

	if (!file || !outputFile)
	{
		cerr << "Womp womp, no such file" << endl;
		return;
	}

	uint64_t C = 0;
	uint64_t C_ = 0;

	while (file.read(reinterpret_cast<char*>(&C), sizeof(C)))
	{
		while (file.read(reinterpret_cast<char*>(&C_), sizeof(C_)))
		{
			uint64_t P = DecryptBlock(C, KL, KO, KI);
			outputFile.write(reinterpret_cast<char*>(&P), sizeof(P));

			C = C_;
		}

		uint64_t P_ = DecryptBlock(C, KL, KO, KI);
		char* p_bytes = reinterpret_cast<char*>(&P_);

		int bytes = 8;
		while (bytes > 0 && p_bytes[bytes - 1] == 0x00)
		{
			bytes--;
		}

		if (bytes > 0)
		{
			outputFile.write(p_bytes, bytes);
		}
	}

	file.close();
	outputFile.close();
}
