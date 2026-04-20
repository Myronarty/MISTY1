#include "Cipher_funcs.h"

uint64_t MISTY1(uint64_t P, uint16_t(&KL)[10][2], uint16_t(&KO)[8][4], uint16_t(&KI)[8][3])
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

uint64_t deMISTY1(uint64_t C, uint16_t(&KL)[10][2], uint16_t(&KO)[8][4], uint16_t(&KI)[8][3])
{

}
