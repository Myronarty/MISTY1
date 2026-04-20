#pragma once
#include "string"
#include "iostream"
#include "cmath"
#include "vector"
#include <fstream>
#include <intrin.h>

using namespace std;

void getK(string file, uint64_t(&K)[2]);

void Expansion(uint64_t K[2], uint16_t(&KL)[2], uint16_t(&KO)[4], uint16_t(&KI)[3]);
