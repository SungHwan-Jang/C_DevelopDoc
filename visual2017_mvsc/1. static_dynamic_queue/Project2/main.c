#include <stdio.h>
//#include "dynamic_queue.h"
#include "static_queue.h"
#include "dynamic_queue_ptr.h"

#define _TEST_DYNAMIC_QUEUE_ 0
#define _TEST_DYNAMIC_QUEUE_PTR_ 1
#define _TEST_STATIC_QUEUE_ 0

int main(void) {

#if _TEST_DYNAMIC_QUEUE_

	DYNAMIC_QUEUE_t* head = NULL;
	unsigned int res = 0;
	int i = 0;

	for (i = 0; i < 0x10; i++) {
		enqueue_d(&head, i);
	}

	display_all_queue_d(&head);

	for (i = 0; i < 0x12; i++) {
		printf("ret Val: %u\n", dequeue_d(&head, &res));
		printf("%u\n", res);
	}

#elif _TEST_DYNAMIC_QUEUE_PTR_

	DYNAMIC_QUEUE_t* head = NULL;
	unsigned int res = 0;
	int i = 0;

	for (i = 0; i < 0x10; i++) {
		head = enqueue_d2(head, i);
	}

	display_all_queue_d2(head);

	for (i = 0; i < 0x12; i++) {
		head = dequeue_d2(head, &res);
		printf("%u\n", res);
	}

#elif _TEST_STATIC_QUEUE_

	STATIC_QUEUE_t head;
	unsigned int res = 0;
	int i = 0;

	init_static_queue(&head);
	
	for (i = 0; i < 20; i++) {
		enqueue_s(&head, i);
	}

	display_all_queue_s(&head);

	for (i = 0; i < 20; i++) {
		printf("ret Val: %u\n", dequeue_s(&head, &res));
		printf("%u\n", res);
	}

#endif

	return 0;
}