#include <stdio.h>

int main() {
	int a, b, mid;
	scanf("%d%d", &a, &b);
	mid = a;
	a = b;
	b = mid;
	printf("%d %d\n", a, b);

	return 0;
}