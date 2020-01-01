#include <stdio.h>

#define _USING_STRUCT_POINTER_ 1

#define NUM_NAMES 2

#if _USING_STRUCT_POINTER_ // struct에는 특별한 이유가 없는 이상 pointer가 없는 편이 훨씬 좋다. (Only 값 형태)
typedef struct {
	char* firstname;
	char* lastname;
}name_t;
#else

#endif

int main(void) {
	name_t names;
	name_t clone;
	char firstName[] = "jang";
	char lastName[] = "sunghwan";

	names.firstname = firstName;
	names.lastname = lastName;

	clone = names; // shallow copy, 포인터만 복사. 따라서 두개의 name_t 구조체임에도 멤버변수는 같은 곳을 가리키고 있다.
	names.lastname[0] = 'X';

	printf("origin: %s %s\n", names.firstname, names.lastname);
	printf("clone: %s %s\n", clone.firstname, clone.lastname);

	return 0;
}