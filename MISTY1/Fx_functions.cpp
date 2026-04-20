#include "Fx_functions.h"

uint16_t FI(uint16_t X, uint16_t KI)
{
	uint16_t L_0 = X >> 7;
	uint8_t R_0 = X & 0x7F;

	uint8_t KI_L = KI >> 9;
	uint16_t KI_R = KI & 0x01FF;

	uint16_t R_1 = S_9[L_0] ^ Extnd(R_0);
	uint8_t L_1 = R_0;

	uint8_t R_2 = S_7[L_1] ^ Trunc(R_1) ^ KI_L;
	uint16_t L_2 = R_1 ^ KI_R;

	uint16_t R_3 = S_9[L_2] ^ Extnd(R_2);
	uint8_t L_3 = R_2;

	uint16_t Y = (uint16_t(L_3) << 9) | R_3;
	return Y;
}

uint32_t FO(uint32_t X, uint16_t KO[4], uint16_t KI[3])
{
	uint16_t L_0 = X >> 16;
	uint16_t R_0 = uint16_t(X);

	uint16_t R = R_0;
	uint16_t L = L_0;

	for (int i = 0; i < 3; i++)
	{
		uint16_t temp = R;
		R = FI(L ^ KO[i], KI[i]) ^ R;
		L = temp;
	}

	uint32_t L_32 = L ^ KO[3];

	uint32_t Y = (L_32 << 16) | R;
	return Y;
}

uint32_t FL(uint32_t X, uint16_t KL[2])
{
	uint16_t L = uint16_t(X >> 16);
	uint16_t R = uint16_t(X);

	uint16_t Y_R = (L & KL[0]) ^ R;
	uint32_t Y_L = L ^ (Y_R & KL[1]);

	uint32_t Y = (Y_L << 16) | Y_R;
	return Y;
}

uint32_t FL_1(uint32_t Y, uint16_t KL[2])
{
	uint16_t L = uint16_t(Y >> 16);
	uint16_t R = uint16_t(Y);

	uint32_t X_L = L ^ (R | KL[1]);
	uint16_t X_R = (X_L & KL[0]) ^ R;

	uint32_t X = (X_L << 16) | X_R;
	return X;
}
