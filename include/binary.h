#ifndef __DES_BINARY_H__
#define __DES_BINARY_H__

#include <stddef.h>
#include <stdint.h>

/**
 * 0x012345678
 * 0000 0001 0010 0011 0100 0101 0110 0111 [...]
 * ^  ^    ^                             ^
 * 1  4    8                             32
 */

#define GETBIT64(x,p) (x & (1ULL << (64 - p)))
#define SETBIT64(x,p) (x |= (1ULL << (64 - p)))
// #define CLRBIT(x,p) (x &= ~(1ULL << (63 - p)))

void printbin(uint64_t n, size_t sep);

#endif
