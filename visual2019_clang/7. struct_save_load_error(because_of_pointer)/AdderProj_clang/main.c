#include <stdio.h>
#include "main.h"
#include <string.h>
//#include "adder.h"

#define _READ_FUNC_ 0
#define _WRITE_FUNC 1 //deep copy OK
#define _WRITE_FUNC_USING_STRUCT_POINTER_ 0 //point copy Error
#define _USING_STRUCT_POINTER_ 0 

#define NUM_NAMES 2
#define NAME_LEN 32

#if _USING_STRUCT_POINTER_ // struct에는 특별한 이유가 없는 이상 pointer가 없는 편이 훨씬 좋다. (Only 값 형태)
typedef struct {
	char* firstname;
	char* lastname;
}name_t;
#else
typedef struct {
	char firstname[NAME_LEN];
	char lastname[NAME_LEN];
}name_t;
#endif

int main(void) {
	name_t names[NUM_NAMES];
	FILE* stream;

#if _WRITE_FUNC
	const char* firstName1 = "Teemo";
	const char* lastName1 = "Kim";
	const char* firstName2 = "Lulu";
	const char* lastName2 = "Lee";
#endif

#if _READ_FUNC_
	size_t i;
	size_t read_num;

	stream = fopen("names.txt", "rb");
	read_num = fread(names, sizeof(names[0]), NUM_NAMES, stream);
	for (i = 0; i < read_num; i++) {
		printf("%s %s\n", names[i].firstname, names[i].lastname);
	}
	fclose(stream);
#endif

#if _WRITE_FUNC_USING_STRUCT_POINTER_
	names[0].firstname = "Teemo";
	names[0].lastname = "Kim";
	names[1].firstname = "LuLu";
	names[1].lastname = "Lee";

	stream = fopen("names.txt", "wb");
	fwrite(names, sizeof(names[0]), NUM_NAMES, stream);
	fflush(stream);

	fclose(stream);
#endif

#if _WRITE_FUNC

	strncpy(names[0].firstname, firstName1, NAME_LEN);
	names[0].firstname[NAME_LEN - 1] = '\0';
	strncpy(names[0].lastname, lastName1, NAME_LEN);
	names[0].lastname[NAME_LEN - 1] = '\0';
	strncpy(names[1].firstname, firstName2, NAME_LEN);
	names[0].firstname[NAME_LEN - 1] = '\0';
	strncpy(names[1].lastname, lastName2, NAME_LEN);
	names[0].lastname[NAME_LEN - 1] = '\0';

	stream = fopen("names.txt", "wb");
	fwrite(names, sizeof(names[0]), NUM_NAMES, stream);
	fflush(stream);

	fclose(stream);

#endif


	return 0;
}