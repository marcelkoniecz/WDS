#include "inc/crc8.hpp"
#include "cstring"


uint16_t CRCSingleByte(uint16_t data) {
	uint16_t poly = (POLYNOMIAL << 7);
	for (uint8_t i = 0; i < 8; i++) {
		if ((data & 0x8000) != 0)
			data ^= poly;
		data <<= 1;
	}
	return data;
}

uint16_t CalculateCRC8( char *ptr) {
	uint16_t data = ptr[0] << 8;

	for (int i = 1; i < strlen(ptr); i++) {
		data |= ptr[i];
		data = CRCSingleByte(data);
	}
	data = CRCSingleByte(data);
	return (data >> 8);
}
