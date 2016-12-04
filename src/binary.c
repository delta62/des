#include "binary.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

void printbin(uint64_t n, size_t sep)
{
	for (size_t bit = 1; bit <= 64; bit++) {
		char c = GETBIT64(n, bit) ? '1' : '0';
		putchar(c);
		if (bit % sep == 0)
			putchar(' ');
	}
}
