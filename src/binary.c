#include "binary.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

void print64(uint64_t n)
{
	for (size_t bit = 1; bit <= 64; bit++) {
		char c = GETBIT64(n, bit) ? '1' : '0';
		putchar(c);
		if (bit % 8 == 0)
			putchar(' ');
	}
	putchar('\n');
}

void print56(uint64_t n)
{
	for (size_t bit = 9; bit <= 64; bit++) {
		char c = GETBIT64(n, bit) ? '1' : '0';
		putchar(c);
		if ((bit + 6) % 7 == 0)
			putchar(' ');
	}
	putchar('\n');
}

void print28(uint32_t n)
{
	for (size_t bit = 5; bit <= 32; bit++) {
		char c = GETBIT32(n, bit) ? '1' : '0';
		putchar(c);
		if ((bit + 3) % 7 == 0)
			putchar(' ');
	}
	putchar('\n');
}
