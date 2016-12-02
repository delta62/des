#include <stdio.h>
#include <stdint.h>
#include "key.h"

#define setbit(l,k) (l |= (1 << (k % 64)))
#define clearbit(l,k) (l &= ~(1 << (k % 64)))
#define getbit(l,k) (l & (1 << (k % 64)))

const uint8_t PC_1[] = {
	0x39, 0x31, 0x29, 0x21, 0x19, 0x11, 0x09,
	0x01, 0x3A, 0x32, 0x2A, 0x22, 0x1A, 0x12,
	0x0A, 0x02, 0x3B, 0x33, 0x2B, 0x23, 0x1B,
	0x13, 0x0B, 0x03, 0x3C, 0x34, 0x2C, 0x24,
	0x3F, 0x37, 0x2F, 0x27, 0x1F, 0x17, 0x0F,
	0x07, 0x3E, 0x36, 0x2E, 0x26, 0x1E, 0x16,
	0x0E, 0x06, 0x3D, 0x35, 0x2D, 0x25, 0x1D,
	0x15, 0x0D, 0x05, 0x1C, 0x14, 0x0C, 0x04
};

uint64_t permutedkey(uint64_t key)
{
	uint64_t ret = 0;
	for (unsigned short i = 0; i < 64; i++) {
		setbit(ret, getbit(key, i));
	}
	return ret;
}

void printkey64(uint64_t key)
{
	for (unsigned short i = 0; i < 64; i++) {
		char c = getbit(key, i) ? '1' : '0';
		putchar(c);
		if ((i + 1) % 8 == 0) {
			putchar(' ');
		}
	}
	putchar('\n');
}

void printkey32(uint32_t key)
{
	for (unsigned short i = 0; i < 32; i++) {
		char c = getbit(key, i) ? '1' : '0';
		putchar(c);
		if ((i + 1) % 8 == 0) {
			putchar(' ');
		}
	}
	putchar('\n');
}

void printkey8(uint8_t key)
{
	for (size_t i = 8; i > 0;) {
		char c = getbit(key, --i) ? '1' : '0';
		putchar(c);
	}
}

void printkey16(uint16_t key)
{
	printkey8(key << 8);
	putchar(' ');
	printkey8(key);
}

void printbinary(const void *ptr, const size_t len)
{
	const unsigned char *b = ptr;
	for (size_t i = len; i > 0; i--) {
		for (size_t j = 8; j > 0;) {
			char c = getbit(b[i], --j);
			putchar(c);
		}
	}
}

int main(int argc, char **argv)
{
	uint8_t one8 = 0x01;
	printbinary(&one8, 1);

	//uint64_t one64 = 0x01;
	//printkey64(one64);
	//putchar('\n');
	//uint32_t one32 = 0x01;
	//printkey32(one32);
	//putchar('\n');
	//uint16_t one16 = 0x01;
	//printkey16(one16);
	//putchar('\n');
	//uint8_t one8 = 0x01;
	//printkey8(one8);
	//putchar('\n');

	// uint64_t key = 0x133457799BBCDFF1;
	// printkey(key);
	// uint64_t permuted = permutedkey(key);
	// printkey(permuted);
	return 0;
}
