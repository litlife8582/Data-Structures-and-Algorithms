#ifndef DATA_STRUCTURES_AND_ALGORITHMS_QUEUE_H
#define DATA_STRUCTURES_AND_ALGORITHMS_QUEUE_H

struct Queue {
    int front;
    int rear;
    int size;
    int *Q;
};

void create(struct Queue *q,int size);
int isEmpty(struct Queue *q);
void enqueue(struct Queue *q,int key);
int dequeue(struct Queue *q) ;

#endif //DATA_STRUCTURES_AND_ALGORITHMS_QUEUE_H