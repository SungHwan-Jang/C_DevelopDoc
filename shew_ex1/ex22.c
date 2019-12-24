#include "ex22.h"
#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

int THE_SIZE = 1000; //header에 extern되어있음.

static int THE_AGE = 37; //해당 .c파일에서만 사용된다. 다른 파일에서는 사용불가. private
static double ratio = 1.0;

int get_age(){
	return THE_AGE;
}

void set_age(int age){
	THE_AGE = age;
}

double update_ratio(double new_ratio){
	double old_ratio = ratio;
	ratio = new_ratio;

	return old_ratio;
}

void print_size(){
	log_info("Size is: %d", THE_SIZE);
}

