#include <stdio.h>
#include "key.h"

int main(int argc, char **argv)
{
	for (short i = 0; i < 56; i++) {
		printf("%d ", PC_1[i]);
		if ((i + 1) % 7 == 0) {
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}
