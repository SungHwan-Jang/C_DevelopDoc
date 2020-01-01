#include <stdio.h>

#define _USING_STRUCT_POINTER_ 1

#define NUM_NAMES 2

#if _USING_STRUCT_POINTER_ // struct���� Ư���� ������ ���� �̻� pointer�� ���� ���� �ξ� ����. (Only �� ����)
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

	clone = names; // shallow copy, �����͸� ����. ���� �ΰ��� name_t ����ü�ӿ��� ��������� ���� ���� ����Ű�� �ִ�.
	names.lastname[0] = 'X';

	printf("origin: %s %s\n", names.firstname, names.lastname);
	printf("clone: %s %s\n", clone.firstname, clone.lastname);

	return 0;
}