#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len) {
	int i;
	for (i=0; i<len; i++)
		printf("(%.2x)", start[i] );
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
	show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
	int ival = val;
	float fval = (float) ival;
	int *pval = &ival;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}

int main() {
	//the example in the book
	/*int a = 12345;
	test_show_bytes(a);*/
 
	//exercise 2.5
	/*int val = 087654321;
    byte_pointer valp = (byte_pointer) &val;

    show_int(val);
    show_float((float) val);
    show_pointer(valp);

    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);.*/

    //2.1.5 first paragraph
    char *val = "12345";
    byte_pointer valp = (byte_pointer) val;//this line can be ignored, and change "valp" of line 54 into "val". Both are ok.

    show_bytes(valp, 6);

    return 0;
}
