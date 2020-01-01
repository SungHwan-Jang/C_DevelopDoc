#include <stdio.h>
#include <ctype.h>

int can_print_it(char ch);
void print_letters(char arg[]);
void print_arguments(int argc, char* argv[]);


int main(int argc, char* argv[]){
	
	print_arguments(argc-1, &argv[1]);
	// argv[0]은 char*로 현재 실행된 디렉터리 정보를 전달한다.

	return 0;
}


int can_print_it(char ch){

	return isalpha(ch) || isblank(ch);
}

void print_letters(char arg[]){
	
	int i=0;

	for(i=0; arg[i] != '\0'; i++){
		char ch = arg[i];
		if(can_print_it(ch)){
			printf("'%c' == %d ",ch, ch);
		}
	}
}

void print_arguments(int argc, char* argv[]){

	int i=0;

	for(i=0; i<argc;i++){
		print_letters(argv[i]);
	}
}

