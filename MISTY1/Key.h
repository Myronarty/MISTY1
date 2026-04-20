#pragma once
#include "string"
#include "iostream"
#include "cmath"
#include "vector"
#include <fstream>
#include <intrin.h>
#include "Fx_functions.h"

using namespace std;

struct RoundKeys
{
    uint16_t KL[2];
    uint16_t KO[4];
    uint16_t KI[3];
};

void getK(string file_name, uint16_t(&K)[8]);

void Expansion(uint64_t K[2], RoundKeys(&Keys)[10]);
