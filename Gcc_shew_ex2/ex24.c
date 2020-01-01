#include <stdio.h>
#include "dbg.h"

#define MAX_DATA 100

typedef enum eyeColor{
	BLUE_EYE, GREEN_EYE, BROWN_EYE, BLACK_EYE, OTHER_EYE
}eyeColor;

const char *EYE_COLOR_NAMES[] = {
	"Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person{
	int age;
	char firstName[MAX_DATA];
	char lastName[MAX_DATA];
	eyeColor eyes;
}Person;

int main(int argc, char** argv){
	Person you = {.age = 0};
	int i =0;
	char *in = NULL;

	printf("FName?");
	in = fgets(you.firstName, MAX_DATA-1, stdin);
	check(in != NULL, "Failed read first Name");

	printf("LName?");
	in = fgets(you.lastName, MAX_DATA-1, stdin);
	check(in != NULL, "Failed read last Name");
	
	printf("Old?");
	int rc = fscanf(stdin, "%d", &you.age);
	check(rc > 0, "Number Plz");

	printf("What color are your eye?\n");
	for (i = 0; i <= OTHER_EYE; i++) {
		printf("(%d) %s\n", i, EYE_COLOR_NAMES[i]);
	}

	int mEye = -1;
	fscanf(stdin, "%d", &mEye);
	you.eyes = mEye;
	check(you.eyes <= OTHER_EYE && you.eyes >= 0, "You haveto enter Numb");
	

	printf("===========RESULT==========\n");
	printf("First Name: %s", you.firstName);
	printf("Last Name: %s", you.lastName);
	printf("Age: %d", you.age);
	printf("Eyes: %s", EYE_COLOR_NAMES[you.eyes]);

	fscanf(stdin, "%d", mEye);

	return 0;

error:
	return -1;
}
