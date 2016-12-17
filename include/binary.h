#ifndef __DES_BINARY_H__
#define __DES_BINARY_H__

#include <stddef.h>
#include <stdint.h>

/**
 * 0x012345678
 * 0000 0001 0010 0011 [...]
 * ^  ^    ^         ^
 * 1  4    8         16
 */

#define GETBIT64(x,p) ((x) & (1ULL << (64 - (p))))
#define GETBIT56(x,p) ((x) & (1ULL << (56 - (p))))
#define GETBIT32(x,p) ((x) & (1UL  << (32 - (p))))
#define SETBIT56(x,p) ((x) |= (1ULL << (56 - (p))))
#define SETBIT48(x,p) ((x) |= (1ULL << (48 - (p))))
#define ROL28(x,n) ((((x) << (n)) | ((x) >> (28 - (n)))) & 0xFFFFFFF)
#define COMBO28(x, y) (((x) | 0ULL) << 28 | (y))

void print64(uint64_t n);
void print56(uint64_t n);
void print48(uint64_t n);
void print32(uint32_t n);
void print28(uint32_t n);

#endif
