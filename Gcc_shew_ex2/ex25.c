#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "dbg.h"

#define MAX_DATA 100

int ReadString(char **out_string, int max_buffer);
int ReadInt(int* out_int);
int ReadScan(const char *fmt, ...);

int main(int argc, char** argv) {

	char *first_name = NULL;
	char initial = ' ';
	char *last_name = NULL;
	int age = 0;

	printf("What is your first name?");
	int rc = ReadScan("%s", MAX_DATA, &first_name);
	check(rc == 0, "Falied first name");

	printf("What is your initial?");
	rc = ReadScan("%c\n", &initial);
	check(rc == 0, "Falied initial");

	printf("What is your last name?");
	rc = ReadScan("%s", MAX_DATA, &last_name);
	check(rc == 0, "Falied last_name");

	printf("How old are you?");
	rc = ReadScan("%d", &age);

	printf("===========RESULT==========\n");

	printf("First Name: %s", first_name);
	printf("Initial: %c", initial);
	printf("Last Name: %s", last_name);
	printf("Age: %d\n", age);

	free(first_name);
	free(last_name);

	scanf("%c", &initial);

	return 0;


error:
	return -1;
}

int ReadString(char **out_string, int max_buffer) {
	*out_string = malloc(sizeof(char)* (max_buffer + 1));
	check_mem(*out_string);

	char *result = fgets(*out_string, max_buffer, stdin); //fgets는 줄바꿈 문자까지 먹어버리는 문제점이있다. fgetc로 적절히 처리해야한다.
	check(result != NULL, "Input Error");
	return 0;

error:
	if (*out_string)
		free(*out_string);
	*out_string = NULL;
	return -1;
}
int ReadInt(int* out_int) {
	char *input = NULL;
	int rc = ReadString(&input, MAX_DATA);
	check(rc == 0, "Failed to read number");

	*out_int = atoi(input);

	free(input);
	return 0;

error:
	if (input)
		free(input);
	return -1;
}
int ReadScan(const char *fmt, ...) {
	int i = 0;
	int rc = 0;
	int *out_int = NULL;
	char *out_char = NULL;
	char **out_string = NULL;
	int max_buffer = 0;

	va_list argp;
	va_start(argp, fmt); // 첫번쨰 인수 및 va_list 타입 자료구조 초기화 기능.

	for (i = 0; fmt[i] != '\0'; i++) {
		if (fmt[i] == '%') {
			i++;
			switch (fmt[i])
			{
			case '\0':
				sentinel("Invalid format, you ended with %%.");
				break;
			case'd':
				out_int = va_arg(argp, int*); // 2번쨰 인수
				rc = ReadInt(out_int);
				check(rc == 0, "Failed to read int");
				break;
			case'c':
				out_char = va_arg(argp, char*); // 2번쨰 인수
				*out_char = fgetc(stdin); 
				break;
			case's':
				max_buffer = va_arg(argp, int); // 2번쨰 인수
				out_string = va_arg(argp, char**); // 3번째 인수
				rc = ReadString(out_string, max_buffer);
				check(rc == 0, "Failed to read string");
				break;
			default:
				sentinel("Invalid Format");
				break;
			}
		}
		else {
			fgetc(stdin); // remove enter.
		}
		check(!feof(stdin) && !ferror(stdin), "Input error.");
	}

	va_end(argp);
	return 0;

error:
	va_end(argp);
	return -1;
}
