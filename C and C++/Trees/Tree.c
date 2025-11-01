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

void enqueue(struct Queue *q,struct Node* x){
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

int isEmpty(struct Queue *q){
    return q->front==q->rear;
}

struct Node *root=NULL;
void createTree() {
    struct Queue q;
    create(&q,100);
    struct Node *p,*t;
    root=(struct Node*)malloc(sizeof(struct Node));
    int x;
    printf("Enter the root data:");
    scanf("%d",&x);
    root->data=x;
    root->lChild=root->rChild=NULL;
    enqueue(&q,root);
    while (!isEmpty(&q)){
        p=dequeue(&q);
        printf("Enter the left child:");
        scanf("%d",&x);
        if (x!=-1) {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=x;
            t->lChild=t->rChild=NULL;
            p->lChild=t;
            enqueue(&q,t);
        }
        printf("Enter the right child:");
        scanf("%d",&x);
        if (x!=-1) {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=x;
            t->lChild=t->rChild=NULL;
            p->rChild=t;
            enqueue(&q,t);
        }
    }
}

void preorder(struct Node *t) {
    if (t!=NULL) {
        printf("%d ",t->data);
        preorder(t->lChild);
        preorder(t->rChild);
    }
}

int main() {
    createTree();
    preorder(root);
    return 0;
}

