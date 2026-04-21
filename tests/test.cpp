#include <gtest/gtest.h>
#include "Cipher_funcs.h"
#include "Key.h"
#include <sstream>
#include <iomanip>

uint64_t hexToUint64(const std::string& hex)
{
    uint64_t val;
    std::stringstream ss;
    ss << std::hex << hex;
    ss >> val;
    return val;
}

void hexToKey(const std::string& hex, uint16_t K[8])
{
    for (int i = 0; i < 8; i++)
    {
        std::string part = hex.substr(i * 4, 4);
        K[i] = (uint16_t)std::stoul(part, nullptr, 16);
    }
}

std::string keyToHex(uint16_t K[8])
{
    std::stringstream ss;
    for (int i = 0; i < 8; i++)
    {
        ss << std::hex << std::setw(4) << std::setfill('0') << K[i];
    }
    return ss.str();
}

TEST(MISTY1, TestVector1)
{
    uint16_t K[8];
    uint16_t KI[8][3], KO[8][4], KL[10][2];

    hexToKey("00112233445566778899aabbccddeeff", K);

    Expansion(K, KI, KO, KL);

    uint16_t K_[8];
    for (int i = 0; i < 7; i++)
    {
        K_[i] = FI(K[i], K[i + 1]);
    }
    K_[7] = FI(K[7], K[0]);

    EXPECT_EQ(keyToHex(K_), "cf518e7f5e29673acdbc07d6bf355e11");

    uint64_t P = hexToUint64("0123456789abcdef");
    uint64_t C = EncryptBlock(P, KL, KO, KI);

    EXPECT_EQ(C, hexToUint64("8b1da5f56ab3d07c"));
}

TEST(MISTY1, TestVector2)
{
    uint16_t K[8];
    uint16_t KI[8][3], KO[8][4], KL[10][2];

    hexToKey("414afd99bb577ee69df58cc8fb4e6888", K);
    Expansion(K, KI, KO, KL);

    uint16_t K_[8];
    for (int i = 0; i < 7; i++)
        K_[i] = FI(K[i], K[i + 1]);
    K_[7] = FI(K[7], K[0]);

    EXPECT_EQ(keyToHex(K_), "c7bd6e012268237a4389305a1b360b8c");

    uint64_t P = hexToUint64("9fc302e281310e90");
    uint64_t C = EncryptBlock(P, KL, KO, KI);

    EXPECT_EQ(C, hexToUint64("15c270974b9b9163"));
}
