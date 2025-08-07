#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct queue *q,int size){
    q->size=size;
    q->Q=(int *)malloc(q->size*sizeof(int));
    q->front=-1;
    q->rear=-1;
}

void enqueue(struct queue *q,int x){
    if(q->rear==q->size-1){
        printf("The queue is full");
    }else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct queue *q){
    int x=-1;
    if(q->front==q->rear){
        printf("The queue is empty");
    }else{
        q->front--;
        x=q->Q[q->front];
    }
    return x;
}

int display(struct queue q){
    for(int i=q.front+1;i<=q.rear;i++){
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}

int main(){
    struct queue qu;

    int queuesize;
    printf("Enter the size of the queue:");
    scanf("%d",&queuesize);
    
    create(&qu,queuesize);

    
    int n;
    printf("Enter the number of elements you want to enqueue: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        enqueue(&qu,num);
    }

    display(qu);

    printf("Enter the number of elements you want to dequeue: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        dequeue(&qu);
    }
    printf("\n");
    
    display(qu);
    
    return 0;
}
