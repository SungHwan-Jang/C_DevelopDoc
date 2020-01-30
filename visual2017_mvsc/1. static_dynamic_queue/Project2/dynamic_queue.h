#ifndef _DYNAMIC_QUEUE_H_
#define _DYNAMIC_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct _dynamic_queue_dat {
	unsigned int val;
	struct _dynamic_queue_dat* link;
}DYNAMIC_QUEUE_t;

void enqueue_d(DYNAMIC_QUEUE_t** head, unsigned int pValue);

int dequeue_d(DYNAMIC_QUEUE_t** head, unsigned int* enqData);

void display_all_queue_d(DYNAMIC_QUEUE_t** head);

#endif