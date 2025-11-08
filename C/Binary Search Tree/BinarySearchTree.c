#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node* lChild;
    struct Node* rChild;
    int data;
};

struct Node* search(struct Node *t,int key) {
    while (t!=NULL) {
        if (key==t->data) return t;
        else if (key>t->data) t=t->rChild;
        else t=t->lChild;
    } return NULL;
}

struct Node* root=NULL;

void insert(struct Node *t,int key) {
    struct Node *r=NULL,*p;

    //To begin the tree building(necessary)
    if (root==NULL) {
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=key;
        p->lChild=p->rChild=NULL;
        root=p;
        return;
    }
    while (t!=NULL) {
        r=t;
        if (key==t->data) {
            printf("Element Present in the tree\n");
            return ;
        }
        else if (key>t->data) t=t->rChild;
        else t=t->lChild;
    }
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=key;
    p->lChild=p->rChild=NULL;
    if (p->data<r->data) r->lChild=p;
    else r->rChild=p;
}

void inorder(struct Node *t) {
    if (t!=NULL) {
        inorder(t->lChild);
        printf("%d ",t->data);
        inorder(t->rChild);
    }
}

int main() {
    int key;
    do{
        printf("Enter the value to be inserted: ");
        scanf("%d",&key);

        if (key!=-1) insert(root,key);//prevents inserting the -1 in the list
    }while (key!=-1);

    inorder(root);

    printf("\nEnter the element to be searched: ");
    scanf("%d",&key);
    struct Node* s=search(root,key);
    if (s==NULL) printf("The element is not in the tree\n");
    else printf("The element is in the tree\n");
    return 0;
}