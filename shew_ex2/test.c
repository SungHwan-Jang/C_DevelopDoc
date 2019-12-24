#include <stdio.h>
#include <string.h>

void sleep(int tick);


int main(int argc, char** argv){

	int age = 33;
	int height = 173;

	char *tmpName = "JANG Sung Hwan";
	char a = 'a';

	printf("Age : %d\n", age);
	printf("Height : %d\n", height);
	printf("%s\n", tmpName);
	printf("Age: %d Height: %d tmpName: %d char : %d\n", sizeof(age), sizeof(height), sizeof(tmpName), sizeof(a));

	sleep(10000);
	scanf("%d", &age);
	sleep(10000);

	return 0;

}

void sleep(int tick){
	while(tick){
		tick--;
	}
}

