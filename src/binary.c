#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define SETBIT(x,p) (x |= (1 << p))
#define CLRBIT(x,p) (x &= ~(1 << p))
#define GETBIT(x,p) (x & (1 << p))

void printbin(const void *ptr, size_t bytes)
{
	for (size_t i = bytes; i > 0;) {
		uint8_t b = ((uint8_t *)ptr)[--i];
		for (size_t j = 8; j > 0;) {
			char c = GETBIT(b, --j) ? '1' : '0';
			putchar(c);
		}
		if (i > 0) {
			putchar(' ');
		}
	}
}
