#pragma once
#include "S_boxes.h"

uint16_t FI(uint16_t X, uint16_t KI);

uint32_t FO(uint32_t X, uint16_t KO[4], uint16_t KI[3]);

uint32_t FL(uint32_t X, uint16_t KL[2]);

uint32_t FL_1(uint32_t Y, uint16_t KL[2]);
