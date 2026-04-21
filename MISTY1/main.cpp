#include "Cipher_funcs.h"

int main()
{
	string file = "D:/problems/term_6/crypto/test/document.pdf";
	string out = "D:/problems/term_6/crypto/test/document.pdf.m";
	string file_ = "D:/problems/term_6/crypto/test/document.pdf.m";
	string out_ = "D:/problems/term_6/crypto/test/document__.pdf";
	string k = "D:/problems/term_6/crypto/test/k.txt";

	MISTY1(file, out, k);
	deMISTY1(file_, out_, k);
	//test for tests 1.2
	return 0;
}
