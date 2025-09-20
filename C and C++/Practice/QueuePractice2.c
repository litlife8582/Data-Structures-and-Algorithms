#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q){
    printf("Enter the size of the queue:");
    scanf("%d",&q->size);
    q->front=-1;
    q->rear=-1;
    q->Q=(int *)malloc(q->size*sizeof(int));
    if(q->Q==NULL){
        printf("Menory allocation is unsuccessful\n");
    }else{
        printf("Memory allocation successful\n");
    }
}

bool isEmpty(struct Queue *q){
    if(q->front==q->rear){
        printf("The queue is empty\n");
        return true;
    } 
    else{
        printf("The queue is not empty\n");
        return false;
    } 
}

bool isFull(struct Queue *q){
    if(q->rear==q->size-1){
        printf("The queue is full\n");
        return true;
    }else{
        printf("The queue is not full\n");
        return false;
    }
}

void display(struct Queue *q){
    for(int i=q->front+1;i<=q->rear;i++){
        printf("%d ",q->Q[i]);
    }
    printf("\n");
}

void enqueue(struct Queue *q){
    int x;
    if(!isFull(q)){
        printf("Enter the number to be enqueued\n");
        scanf("%d",&x);
        q->rear++;
        q->Q[q->rear]=x;
    }    
}

int dequeue(struct Queue *q){
    int x;
    if(!isEmpty(q)){
        q->front++;
        x=q->Q[q->front+1];
        return x;
    }else{
        return -1;
    }
}

int main(){
    struct Queue *q;
    printf("Menu:\n");
    printf("1. Create\n");
    printf("2. isEmpty\n");
    printf("3. isFull\n");
    printf("4. Display\n");
    printf("5. Enqueue\n");
    printf("6. Dequeue\n");
    printf("-1.Exit\n");
    int choice;
    do{
        printf("Enter the choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            create(q);
            break;
        
        case 2:
            isEmpty(q);
            break;

        case 3:
            isFull(q);
            break;

        case 4:
            display(q);
            break;

        case 5:
            enqueue(q);
            break;

        case 6:
            printf("The dequeued number is: %d\n",dequeue(q));
            break;

        case -1:
            printf("Exiting......");
            break;
        
        default:
            printf("Invalid Input. Enter valid choice\n");
            break;
        }
    }while(choice!=-1);
    return 0;
}