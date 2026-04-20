#include "Key.h"

void getK(string file_name, uint64_t(&K)[2])
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
        K[0] = _byteswap_uint64(K[0]);
        K[1] = _byteswap_uint64(K[1]);

    }
    else
    {
        cerr << "Womp womp, failed to read key" << endl;
    }

    file.close();
}

void Expansion(uint64_t K[2], uint16_t(&KL)[2], uint16_t(&KO)[4], uint16_t(&KI)[3])
{

}
