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

void Expansion(uint16_t K[8], uint16_t(&KI)[8][3], uint16_t(&KO)[8][4], uint16_t(&KL)[10][2])
{
    uint16_t K_[8] = { 0 };

    for (int i = 0; i < 7; i++)
    {
        K_[i] = FI(K[i], K[i + 1]);
    }
    K_[7] = FI(K[7], K[0]);

    for (int i = 0; i < 8; i++)
    {
        KO[i][0] = K[i % 8];
        KO[i][1] = K[(i + 2) % 8];
        KO[i][2] = K[(i + 7) % 8];
        KO[i][3] = K[(i + 4) % 8];

        KI[i][0] = K_[(i + 5) % 8];
        KI[i][1] = K_[(i + 1) % 8];
        KI[i][2] = K_[(i + 3) % 8];
    }

    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            KL[i][0] = K[(i / 2) % 8];
            KL[i][1] = K_[(i / 2 + 6) % 8];
        }
        else
        {
            KL[i][0] = K_[((i + 1) / 2 + 1) % 8];
            KL[i][1] = K[((i + 1) / 2 + 3) % 8];
        }
    }
}
