#include "Key.h"

void getK(string file_name, uint16_t(&K)[8])
{
    if (!(file_name.ends_with(".txt")))
    {
        cerr << "Womp womp, no such file" << endl;
        return;
    }

    ifstream file(file_name, ios::binary);

    if (!file.is_open())
    {
        cerr << "Womp womp, no such file" << endl;
        return;
    }

    if (file.read(reinterpret_cast<char*>(K), sizeof(K)))
    {
        for (int i = 0; i < 8; i++)
        {
            K[i] = _byteswap_ushort(K[i]);
        }
    }
    else
    {
        cerr << "Womp womp, failed to read key" << endl;
    }

    file.close();
}

void Expansion(uint64_t K[2], RoundKeys(&Keys)[10])
{
    uint64_t K_[2] = { 0 };
    uint64_t u1 = 0;
    uint64_t u2 = 0;

    for(int i = 0; i < )
}
