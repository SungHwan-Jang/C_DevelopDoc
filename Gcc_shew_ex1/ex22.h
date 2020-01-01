#ifndef _ex22_h
#define _ex22_h

#include <stdio.h>
// it is possible to use THE_SIZE to other files 
extern int THE_SIZE;

// get or set static value in the ex22 file.
int get_age();
void set_age(int age);

//update static value in the update_ratio.
//
double update_ratio(double ratio);

void print_size();

#endif
