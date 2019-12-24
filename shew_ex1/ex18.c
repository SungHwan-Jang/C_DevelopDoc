#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char* message){
	if(errno)
		perror(message);
	else
		printf("ERROR: %s\n", message);

	exit(1);
} //에러 처리 함수.

/* 함수 포인터*/
typedef int (*compare_cb) (int a, int b);

int* bubble_sort(int *numbers, int count, compare_cb cmp){
	int temp;
	int i=0;
	int j=0;

	int* target = malloc(count * sizeof(int)); //HEAP 2

	if(!target)
		die("Memmory Error!");

	memcpy(target, numbers, count * sizeof(int));

	for(i=0; i<count; i++){
		for(j=0; j<count-1; j++){
			if(cmp(target[j], target[j+1])>0){
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp;
			}
		}
	}
	return target;
}

int sorted_order(int a, int b){
	return a-b;
}

int reverse_order(int a, int b){
	return b-a;
}

int strange_order(int a, int b){
	if(a==0 || b==0)
		return 0;
	else
		return a%b;
}

void test_sorting(int* numbers, int count, compare_cb cmp){
	int i=0;
	int* sorted = bubble_sort(numbers, count, cmp);

	if(!sorted)
		die("Failed to sort ad requested.");

	for(i=0; i<count; i++){
		printf("%d ", sorted[i]);
	}
	printf("\n");
	free(sorted); //FREE 2
}


int main(int argc, char* argv[]){

	char ch;
	scanf("%c", &ch);

	if(argc <2) die("USAGE: ex18 4 3 1 5 6");

	int count = argc -1;
	int i=0;
	char **inputs = argv+1;

	int *numbers = malloc(count * sizeof(int)); //HEAP 1
	if(!numbers)
		die("Memmory Error!");

	for(i=0; i<count; i++){
		numbers[i] = atoi(inputs[i]);
	}

	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, reverse_order);
	test_sorting(numbers, count, strange_order);

	free(numbers); //FREE 1

	return 0;
}
