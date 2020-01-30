#ifndef _STATIC_QUEUE_H_
#define _STATIC_QUEUE_H_

#include <stdlib.h>
#include <stdio.h>

#define MAX_STATIC_QUEUE 16

typedef int STATIC_QUEUE_t;

static unsigned int queue[MAX_STATIC_QUEUE];

void init_static_queue(STATIC_QUEUE_t* head);

int enqueue_s(STATIC_QUEUE_t* head, unsigned int value);

int dequeue_s(STATIC_QUEUE_t* head, unsigned int* ret);

void display_all_queue_s(STATIC_QUEUE_t* head);

#endif