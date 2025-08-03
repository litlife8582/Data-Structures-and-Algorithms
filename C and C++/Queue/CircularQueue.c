#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int* Q;
};

void create(struct Queue *q){
    printf("Enter the size of queue: ");
    scanf("%d",&q->size);
    q->Q=(int*)malloc(q->size*sizeof(int));
    q->front=q->rear=0;
}

void enqueue(struct Queue *q,int x){
    if((q->rear+1)%q->size==q->front)
        printf("Queue is Full");
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q){
    int x=-1;
    if(q->front==q->rear)
        printf("Queue is Empty");
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

void display(struct Queue q){
    int i;
    if (q.front == q.rear) {
        printf("Queue is empty\n");
        return;
    }
    i = (q.front + 1) % q.size;
    printf("Queue elements: ");
    while(i != (q.rear + 1) % q.size){
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    }
    printf("\n");
}


int main(){
    struct Queue q;
    create(&q);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);

    display(q);

    printf("%d",dequeue(&q));

    return 0;
}