#include <stdio.h>
#include <string.h>

double add(double x, double y);
double sub(double x, double y);
double calculate(double x, double y, double (*func)(double, double));

void (*bsd_signal(int, void(*)(int)))(int);
//params: int, void (*)(int)
//ret: void (*)(int)
// 1. <ret-type> bsd_signal(int, void(*)(int)); 
// 2. void(*)(int) bsd_signal(int, void(*)(int));
// 3. void (*<origin>)(int);
// 4. void (* bsd_signal(int, void(*)(int)))(int);

unsigned int** (*foo)(char(*)(void*));
//ret: unsigned int**
//params : char(*)(void*)

int main(void) {

	double res;
	double (*func)(double, double); // function pointer.

	/*
	<return-type> (*<function name>)(<Params..>)
	*/

	double (*ops[])(double, double) = {add, sub}; // function pointer array

	func = add;

	res = func(10.0, 20.0);
	printf("res = func(10.0, 20.0); is %f\n", res);
	
	res = calculate(20, 10, sub); //call back function.
	printf("res = calculate(20, 10, sub); is %f\n", res);

	res = ops[0](10, 20);
	printf("res = ops[0](10, 20); is %f\n", res);

	return 0;
}

double add(double x, double y) {
	return x + y;
}

double sub(double x, double y) {
	return x - y;
}

double calculate(double x, double y, double (*func)(double, double)) {
	return func(x, y);
}
