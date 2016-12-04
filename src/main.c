#include <stdint.h>
#include "algorithm.h"

int main(int argc, char **argv)
{
	uint64_t k = 0x133457799BBCDFF1;
	uint64_t m = 0x0123456789ABCDEF;
	desencode(k, m);
	return 0;
}
