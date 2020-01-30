#ifndef _DYNAMIC_QUEUE_PTR_H_
#define _DYNAMIC_QUEUE_PTR_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct _dynamic_queue_dat {
	unsigned int val;
	struct _dynamic_queue_dat* link;
}DYNAMIC_QUEUE_t;

DYNAMIC_QUEUE_t* enqueue_d2(DYNAMIC_QUEUE_t* head, unsigned int pValue);

DYNAMIC_QUEUE_t* dequeue_d2(DYNAMIC_QUEUE_t* head, unsigned int* enqData);

void display_all_queue_d2(DYNAMIC_QUEUE_t* head);

#endif