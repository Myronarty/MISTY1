#include "Cipher_funcs.h"

int main()
{
	bool t = 1;

	while (t)
	{
		bool a;
		cout << "Encrypt or decrypt (1/0) \n";
		cin >> a;

		if (a)
		{
			string file;
			string out;
			string k;
			cout << "Path to your data (example: C:/user/data.txt): ";
			cin >> file;
			cout << "Path where to store your encrypted data (example: C:/user/data.txt.C): ";
			cin >> out;
			cout << "Path to your key (only .txt files) (example: C:/user/k.txt): ";
			cin >> k;
			MISTY1(file, out, k);
		}
		else
		{
			string file;
			string out;
			string k;
			cout << "Path to your encrypted data (example: C:/user/data.txt.C): ";
			cin >> file;
			cout << "Path where to store your decrypted data (example: C:/user/data.txt): ";
			cin >> out;
			cout << "Path to your key (only .txt files) (example: C:/user/k.txt): ";
			cin >> k;
			deMISTY1(file, out, k);
		}
	}

	return 0;
}
