#include "static_queue.h"

void init_static_queue(STATIC_QUEUE_t* head) {
	*head = -1;
}

int enqueue_s(STATIC_QUEUE_t* head, unsigned int value) {
	if (*head == -1) {
		*head = 0;
		queue[*head] = value;
		return 1;
	}
	else {
		if (*head > MAX_STATIC_QUEUE - 2) {
			return 0;
		}
		(*head)++;
		queue[*head] = value;
		return 1;
	}
}

int dequeue_s(STATIC_QUEUE_t* head, unsigned int* ret) {
	if (*head < 0) {
		return 0;
	}
	else {
		*ret = queue[*head];
		(*head)--;
		return 1;
	}
}

void display_all_queue_s(STATIC_QUEUE_t* head) {
	int cnt = *head;
	while (cnt)
	{
		printf("%u\n", queue[cnt]);
		cnt--;
	}
}