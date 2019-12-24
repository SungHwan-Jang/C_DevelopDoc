#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>


void test_debug(){
	debug("test_debug()");
}

void test_log_err(){
	log_err("test_log_err()");
}

void test_log_warn(){
	log_warn("test_log_warn");
}

void test_log_info(){
	log_info("test_log_info");
}

int test_check(char *filename){
	FILE *input = NULL;
	char *block = NULL;

	block = malloc(100);
	check_mem(block); // check malloc success

	input = fopen(filename, "r");
        check(input, "Failed to open <%s>", filename);
	free(block);
	fclose(input);
	return 0;

error:
	if(block) free(block); //defensive coding
	if(input) fclose(input); //defensive coding
	return -1;
}

int test_sentinel(int code){
	char *temp = malloc(100);
	check_mem(temp);

	switch(code){
		case 1:
			log_info("sentinal_log_info");
			break;
		default :
			sentinel("sentinal");
	}

	free(temp);
	return 0;

error:
	if(temp)
		free(temp);
	return -1;
}

int test_check_mem(){
	char *test = NULL;
	check_mem(test);
	free(test);
	return 1;

error:
	return -1;
}

int test_check_debug(){
	int i=0;
	check_debug(i != 0, "check_debug");
	return 0;
error:
	return 1;
}



int main(int argc, char** argv){
	
	check(argc == 2, "Need an argument!");
	test_debug();
	test_log_err();
	test_log_warn();
	test_log_info();

	check(test_check("ex19.c") == 0, "fail with ex19.c");
	check(test_check(argv[1]) == -1, "fail with argv");
	check(test_sentinel(1) == 0, "test sentinal failed");
	check(test_sentinel(100) == -1, "test sentinal failed");
	check(test_check_mem() == -1, "fail with test_check_mem");
	check(test_check_debug() == -1, "fail with test_check_debug_failed");

	return 0;

error:
	return -1;
}

