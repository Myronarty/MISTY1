#pragma once
#include "string"
#include "iostream"
#include "cmath"
#include "vector"
#include <fstream>
#include <intrin.h>
#include "Fx_functions.h"

using namespace std;

void getK(string file_name, uint16_t(&K)[8]);

void Expansion(uint16_t K[8], uint16_t(&KL)[8][2], uint16_t(&KO)[8][4], uint16_t(&KI)[10][3]);
