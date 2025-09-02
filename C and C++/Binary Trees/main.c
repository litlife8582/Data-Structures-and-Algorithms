#include "queue.h"
#include<stdio.h>

struct Node *root=NULL;

void TreeCreate(){
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);

    printf("Enter the root value: ");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q)){
        p=dequeue(&q);
        printf("Enter the left child: ");
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }

        printf("Enter the right child: ");
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}

void preorder(struct Node *p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p){
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void postorder(struct Node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}


int main(){
    TreeCreate();
    printf("\nPreoreder output: ");
    preorder(root);
    printf("\nPostorder output: ");
    postorder(root);
    printf("\nInorder output: ");
    inorder(root);
    return 0;
    
}