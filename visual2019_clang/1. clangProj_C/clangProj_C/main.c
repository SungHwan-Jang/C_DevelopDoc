#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#if 1
typedef struct _stack {
	int value;
	struct _stack* addr;
	void (*pushh)();
}STACK;

void push(STACK** stackAddr, int val) {
	STACK* tmp = NULL;

	if ((*stackAddr) == NULL) {
		(*stackAddr) = (STACK*)malloc(sizeof(STACK));
		(*stackAddr)->value = val;
		(*stackAddr)->addr = NULL;
	}
	else {
		tmp = (*stackAddr);
		(*stackAddr) = (STACK*)malloc(sizeof(STACK));
		(*stackAddr)->value = val;
		(*stackAddr)->addr = tmp;
	}
}

int pop(STACK** stackAddr) {
	int ret = 0;
	STACK* addr = NULL;

	if ((*stackAddr) != NULL) {
		ret = (*stackAddr)->value;
		addr = (*stackAddr);
		(*stackAddr) = (*stackAddr)->addr;
		free(addr);

		return ret;
	}
	else {
		printf("Empty Stack");
		return -1;
	}
}
#endif

void do_work(void) {
infinite:
	printf("do work\n");

	goto infinite;
}

int main(void) {
#if 1
	int cmd = 0;
	int val = 0;
	int savedVal = 0;
	STACK* _stack = NULL;
	printf("hello POCU!\n");

	while (1) {
		printf("input cmd\n");
		scanf("%d", &cmd);

		switch(cmd) {
		case 1:
			printf("input value\n");
			scanf("%d", &val);
			push(&_stack, val);
			break;
		case 2:
			savedVal = pop(&_stack);
			printf("pop is %d\n", savedVal);
			break;
		default:
			break;
		}
	}
#endif
	return 0;
}