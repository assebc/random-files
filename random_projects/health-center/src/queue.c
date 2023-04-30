#include "../include/queue.h"

void initQueue(QUEUE q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(QUEUE q) {
    return q->front == -1 && q->rear == -1;
}

int isFull(QUEUE q) {
    return q->rear == MAX_QUEUE_SIZE - 1;
}

void enqueue(QUEUE q, USER u) {
    if (isFull(q)) {
        printf("Error: Queue is full\n");
        return;
    } else if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->arr[q->rear] = u;
}

void dequeue(QUEUE q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    } else if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
}

USER getFront(QUEUE q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return q->arr[q->front];
}

void printQueue(QUEUE q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("QUEUE\n");
    for (int i = q->front; i <= q->rear; i++) {
        listUser(q->arr[i]);
    }
    printf("\n");
}

int size(QUEUE q){
    return q->rear-q->front;
}