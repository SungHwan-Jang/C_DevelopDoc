#include "dynamic_queue.h"

void enqueue_d(DYNAMIC_QUEUE_t** head, unsigned int pValue) {
	if ((*head) == NULL) {
		(*head) = (DYNAMIC_QUEUE_t*)malloc(sizeof(DYNAMIC_QUEUE_t));
		(*head)->val = pValue;
		(*head)->link = NULL;
	}
	else {
		DYNAMIC_QUEUE_t* tmpMalloc = (DYNAMIC_QUEUE_t*)malloc(sizeof(DYNAMIC_QUEUE_t));
		tmpMalloc->val = pValue;
		tmpMalloc->link = (*head);
		(*head) = tmpMalloc;
	}
}

int dequeue_d(DYNAMIC_QUEUE_t** head, unsigned int* enqData) {

	if ((*head) == NULL) {
		*enqData = -1;
		return 0; //ret FALSE
	}
	else {
		DYNAMIC_QUEUE_t* tmp = (*head);
		*enqData = tmp->val;
		(*head) = tmp->link;
		free(tmp);
		tmp = NULL;

		return 1; //ret TRUE
	}
}

void display_all_queue_d(DYNAMIC_QUEUE_t** head) {
	if ((*head) == NULL)
		return;

	printf("%u\n", (*head)->val);
	display_all_queue_d(&((*head)->link));
}