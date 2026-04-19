#include "S_boxes.h"

uint16_t Extnd(uint8_t R)
{
	return (uint16_t)(R & 0x7F);
}

uint8_t Trunc(uint16_t R)
{
	return (uint8_t)(R & 0x7F);
}
