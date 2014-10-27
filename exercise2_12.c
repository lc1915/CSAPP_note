#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned int x = 0x87654321;
	int w = 32;

	unsigned int xA, xB, xC;
	xA = x & 0xFF;
	xB = ~x ^ 0xFF;
	xC = x | 0xFF;
	int w0 = w / 4 + 2;
	printf("%#010x\n", xA);
	printf("%#010x\n", xB);
	printf("%#010x\n", xC);
}
