#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    struct Node *next;
} *first = NULL;

void create(char arr[],int n){
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    last = first;
    first->data=arr[0];
    first->next = NULL;

    for(int i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void insertAtEnd(char inp){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = inp;
    struct Node *p;
    p = first;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next = t;
    t->next=NULL ;
}

char delete(int n){
    struct Node *p, *q;
    int x=-1;
    if(n<1 || first==NULL){
        return x;
    }
    if(n == 1){
        p=first;
        x=p->data;        
        first=first->next;
        free(p);
    }else{
        p = first;
        q = NULL;
        for (int i = 0; i < n - 1 && p; i++){
            q = p;
            p = p->next;
        }
        if (p){            
            q->next = p->next;
            x = p->data;
            free(p);
        }
    }
    return x;
}

void display(){
    struct Node* p;
    p=first;
    while(p!=NULL){
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}


int main(){
    char arr[]={'X','Y','Z','A'};
    create(arr,4);
    printf("Original List:\n");
    display();

    insertAtEnd('B');
    printf("List after adding B at the end:\n");
    display();
    
    delete(1);
    printf("List after deletion of node at beginning:\n");
    display();
    return 0;
}