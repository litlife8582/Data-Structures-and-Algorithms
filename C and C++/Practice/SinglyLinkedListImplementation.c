//Linked List: Implement a Singly Linked List with all operations such as Insertion at Beginning, Middle, End; Deletion from Beginning, Middle, End; and Traversal.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;
}*first=NULL;

void creation(int x){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;
    if(first==NULL) first=newNode;
    else{
        struct Node* t=first;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=newNode;
    }
}

void insertion(int x,int n){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node)); 
    newNode->data=x;
    newNode->next=NULL;

    if(n==1){
        newNode->next=first;
        first=newNode;
    }
    else{
        struct Node* temp=first;
        for(int i=0;i<n-2 && temp!=NULL ;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }  
}

int deletion(int n){
    struct Node* previousNode=first;
    struct Node* nodeToDelete=NULL;
    int value=-1;
    if(n!=1){
        for(int i=0;i<n-2;i++){
            if(previousNode==NULL || previousNode->next==NULL){
                printf("Position is out of bound\n");
                return -1;
            }
            previousNode=previousNode->next;
        }
        nodeToDelete=previousNode->next;
        previousNode->next=previousNode->next->next;
        value=nodeToDelete->data;
        free(nodeToDelete);
    }
    else if(n==1){
        nodeToDelete=first;
        value=nodeToDelete->data;
        first=first->next;
        free(nodeToDelete);
    }
    return value;
}

void traversal(){
    struct Node* t=first;
    while(t){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}

int main(){
    struct Node* node;
    printf("Menu\n");
    printf("1.Creation\n");
    printf("2.Insertion\n");
    printf("3.Deletion\n");
    printf("4.Traversal\n");
    printf("-1.Exit\n");
    int choice;
    do{
        printf("Enter the choice:\n");
        scanf("%d",&choice);
        switch (choice){
        case 1:
            printf("Enter the number of elements to insert:\n");
            int size;
            int element;
            scanf("%d",&size);
            for(int i=0;i<size;i++){
                printf("Enter the element: \n");
                scanf("%d",&element);
                creation(element);
            }
            break;

        case 2:
            printf("Enter the index to be inserted in: ");
            int index;
            scanf("%d",&index);
            printf("Enter the value to be inserted: ");
            int value;
            scanf("%d",&value);
            insertion(value,index);
            break;

        case 3:
            printf("Enter the index of the value to be deleted: ");
            scanf("%d",&index);
            deletion(index);
            break;

        case 4:
            traversal();
            break;

        case -1:
            printf("Exiting.....");
            break;

        default:
            printf("Invalid Input. Enter valid inputs\n");
            break;
        }      
    }while(choice!=-1);
    return 0;
}