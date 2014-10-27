#include <stdio.h>
#include <limits.h>

//exercise 2.10
void inplace_swap(int *x, int *y) {
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {
	int first, last;
	for(first = 0, last = cnt - 1;
		first < last;
		first++, last--)
		inplace_swap(&a[first], &a[last]);
}

int main() {
	int a[] = {1,2,3,4,5,6};
	int cnt = 6;
	int i;

	reverse_array(a, cnt);

	for(i = 0; i < cnt; i++) {
		printf("%d\n", a[i]);
	}
	

	return 0;
}