#include "Cipher_funcs.h"

int main()
{
	string file = "D:/problems/term_6/crypto/pu_pu_pu.txt";
	string out = "D:/problems/term_6/crypto/pu_pu_pu.txt.m";
	string file_ = "D:/problems/term_6/crypto/pu_pu_pu.txt.m";
	string out_ = "D:/problems/term_6/crypto/pu_pu_pu__.txt";
	string k = "D:/problems/term_6/crypto/k.txt";

	MISTY1(file, out, k);
	deMISTY1(file_, out, k);

	return 0;
}
