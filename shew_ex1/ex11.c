#include <stdio.h>

int main(void){

	int numbers[4] = {0,};
	char name[4] = {'a',};

	// first, init array 
	
	printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]);

	printf("name: %s\n", name);

	// setup numbers array
	
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;

	//setup name array
	
	name[0] = 'Z';
	name[1] = 'e';
	name[2] = 'd';
	name[3] = '\0';

	//then, display setup array
	
	printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]);

	// display name array to string.
	
	printf("name: %s\n", name);

	// this is another method for using string.
	
	char *another = "Zed";

	printf("another: %s\n", another);
	printf("another each: %c %c %c %c\n", another[0], another[1], another[2], another[3]);


	name[0] = 0x11;
	name[1] = 0x11;
	name[2] = 0x00;
	name[3] = 0x00;

	int* tmp = name;

	printf("this is %d\n", *tmp);
	
	return 0;
}
