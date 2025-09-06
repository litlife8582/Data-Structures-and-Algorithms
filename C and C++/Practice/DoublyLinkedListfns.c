#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    char data;
    struct Node *next;
} *first = NULL;

void create(char arr[],int n){
    if (n == 0) return;
    struct Node *t,*last;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for(int i=1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void insertAtBeginning(char inp){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = inp;
    t->prev = NULL;
    if(first == NULL){
        t->next = NULL;
        first = t;
    } else {
        t->next = first;
        first->prev = t;
        first = t;
    }
}

void deleteAtEnd(){
    if(first == NULL){
        return;
    }
    if(first->next == NULL){
        free(first);
        first = NULL;
        return;
    }
    struct Node *p = first;
    while(p->next != NULL){
        p = p->next;
    }
    p->prev->next = NULL;
    free(p);
}

void display(){
    struct Node* p = first;
    if(p == NULL) {
        printf("List is empty.\n");
        return;
    }
    while(p!=NULL){
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    char arr[]={'U','V','W','X'};
    create(arr,4);
    printf("Original List:\n");
    display();

    insertAtBeginning('T');
    printf("List after inserting 'T' at the beginning:\n");
    display();

    deleteAtEnd();
    printf("List after deleting the node at the end:\n");
    display();

    return 0;
}