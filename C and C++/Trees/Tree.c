#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node* lChild;
    struct Node* rChild;
    int data;
};

struct Queue{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(struct Node**)malloc(q->size*sizeof(struct Node*));
}

struct Node* enqueue(struct Queue *q,struct Node* x){
    if(q->rear==q->size-1)
        printf("Queue is full");
    else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}

struct Node* dequeue(struct Queue *q){
    struct Node *x=NULL;
    if(q->front==q->rear){
        printf("Queue is Empty");
    }else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q){
    return q->front==q->rear;
}

struct Node* root=NULL;
int main() {
    struct Queue q;
    struct Node *p,*t;
    root=(struct Node*)malloc(sizeof(struct Node));
    int x;
    printf("Enter the root data:");
    scanf("%d",&x);
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(root);


    return 0;
}

