#include "Cipher_funcs.h"

int main()
{
	string file = "D:/problems/term_6/crypto/test/pu_pu_pu.txt";
	string out = "D:/problems/term_6/crypto/test/pu_pu_pu.txt.m";
	string file_ = "D:/problems/term_6/crypto/test/pu_pu_pu.txt.m";
	string out_ = "D:/problems/term_6/crypto/test/pu_pu_pu__.txt";
	string k = "D:/problems/term_6/crypto/test/k.txt";
	string k_ = "D:/problems/term_6/crypto/test/k1.txt";

	uint16_t K[8] = { 0 };
	getK(k_, K);

	uint16_t KI[8][3] = { 0 };
	uint16_t KO[8][4] = { 0 };
	uint16_t KL[10][2] = { 0 };

	Expansion(K, KI, KO, KL);

	//cout << std::hex << DecryptBlock(EncryptBlock(0x0123456789abcdef, KL, KO, KI), KL, KO, KI);

	cout << "\n" << std::hex << EncryptBlock(0x0123456789abcdef, KL, KO, KI);

	//MISTY1(file, out, k);
	//deMISTY1(file_, out_, k);

	return 0;
}
