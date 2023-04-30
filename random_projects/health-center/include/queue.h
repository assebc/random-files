#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

#include "define.h"
#include "user.h"

typedef struct queue {
    USER arr[MAX_QUEUE_SIZE];
    int front;
    int rear;
} * QUEUE;

void initQueue(QUEUE q);
int isEmpty(QUEUE q);
int isFull(QUEUE q);
void enqueue(QUEUE q, USER u);
void dequeue(QUEUE q);
USER getFront(QUEUE q);
void printQueue(QUEUE q);
int size(QUEUE q);

#endif