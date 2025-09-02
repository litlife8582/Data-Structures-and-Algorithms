#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;    
}*first=NULL;

struct Node* create(int value){
    struct Node *p=(struct Node*)malloc(sizeof(struct Node));
    if(!p){
        printf("Memory Allocation Failed");
        exit(0);
    }  
    p->data=value;
    p->next=NULL;
    return p;
}

void display(struct Node* p){
    p=first;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void insert(int value, int pos){
    struct Node *t,*p;
    t=create(value);

    if(pos==1){
        t->next=first;
        first=t;
    }else{
        t=first;
        for(int i=1;i<pos;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }   
}

void main(){
    
}