#pragma once
#include "Key.h"
#include <cstdint>

uint64_t EncryptBlock(uint64_t P, uint16_t(&KL)[10][2], uint16_t(&KO)[8][4], uint16_t(&KI)[8][3]);

uint64_t DecryptBlock(uint64_t C, uint16_t(&KL)[10][2], uint16_t(&KO)[8][4], uint16_t(&KI)[8][3]);

void MISTY1(string file_name, string out_name, string file_k);

void deMISTY1(string file_name, string out_name, string file_k);
