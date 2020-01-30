#include "dynamic_queue_ptr.h"

DYNAMIC_QUEUE_t* enqueue_d2(DYNAMIC_QUEUE_t* head, unsigned int pValue) {

	if (head == NULL) {
		head = (DYNAMIC_QUEUE_t*)malloc(sizeof(DYNAMIC_QUEUE_t));
		head->val = pValue;
		head->link = NULL;
		return head;
	}
	else {
		DYNAMIC_QUEUE_t* queueMalloc = (DYNAMIC_QUEUE_t*)malloc(sizeof(DYNAMIC_QUEUE_t));
		queueMalloc->val = pValue;
		queueMalloc->link = head;
		head = queueMalloc;
		return head;
	}
}

DYNAMIC_QUEUE_t* dequeue_d2(DYNAMIC_QUEUE_t* head, unsigned int* enqData) {

	if (head == NULL) {
		*enqData = -1;
		return head;
	}
	else {
		DYNAMIC_QUEUE_t* tmp = head;
		*enqData = tmp->val;
		head = tmp->link;
		free(tmp);
		tmp = NULL;

		return head;
	}
}

void display_all_queue_d2(DYNAMIC_QUEUE_t* head) {
	if (head == NULL)
		return;

	printf("%u\n", head->val);
	display_all_queue_d2(head->link);
}