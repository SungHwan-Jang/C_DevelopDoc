#include <stdio.h>
#include "adder.h"

int main(void) {
	const int res = add(1, 2); 
	printf("%d\n", res);
	return 0;
}