#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


typedef int (*compare_ordering)(int a, int b);

int reverse_cmp(int a, int b){
	return b-a;
}

int rising_cmp(int a, int b){
	return a-b;
}

int* bubble_sort(int* target, int count, compare_ordering cmpval){
	int i,j;
	int tmp;

	for(i=0; i<count-1; i++){
		for(j=i; j<count; j++){
			if(cmpval(target[i], target[j])>0){
				tmp = target[i];
				target[i] = target[j];
				target[j] = tmp;
			}
		}
	}

	return target;
}

void print_all(int* target, int count){
	int i=0;

	while(count){
		printf("%d ", target[i]);
		i++;
		count--;
	}
	printf("\n");
}

int main(int argc, char** argv){

	int count = argc-1;
	int* numbers = malloc(sizeof(int)*count);
	if(!numbers)
		printf("error");
	int i;

	for(i=0; i<count; i++){
		numbers[i] = atoi(argv[i+1]);
	}

	bubble_sort(numbers, count, rising_cmp);
	print_all(numbers, count);

	bubble_sort(numbers, count, reverse_cmp);
	print_all(numbers, count);

	free(numbers);

	return 0;
}
