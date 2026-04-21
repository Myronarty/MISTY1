#pragma once
#include "string"
#include "iostream"
#include "cmath"
#include "vector"
#include <cstdint>
#include <fstream>
#include "Fx_functions.h"

using namespace std;

void getK(string file_name, uint16_t(&K)[8]);

void Expansion(uint16_t K[8], uint16_t(&KI)[8][3], uint16_t(&KO)[8][4], uint16_t(&KL)[10][2]);
