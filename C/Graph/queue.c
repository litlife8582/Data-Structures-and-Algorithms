//
// Created by Mayuk on 05-11-2025.
//
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void create(struct Queue *q,int size) {
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int*)malloc(q->size*sizeof(int));
}

int isEmpty(struct Queue *q) {
    if (q->front==q->rear) return 1;
    else return 0;
}

int isFull(struct Queue *q) {
    if (q->front==q->size-1) return 1;
    else return 0;
}

void enqueue(struct Queue *q,int key){
    if (isFull(q)) printf("The queue is full\n");
    else{
        q->rear++;
        q->Q[q->rear]=key;
    }
}

int dequeue(struct Queue *q) {
    int x;
    if (isEmpty(q)) {
        printf("The queue is empty\n");
        return -1;
    }
    else {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}