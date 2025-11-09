#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;
}*first=NULL;

void insertionLast(int x){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node*));
    if(newNode==NULL){
        printf("Memory Allocation Successful\n");
    }
    newNode->data=x;
    newNode->next=NULL;
    if(first==NULL){
        first=newNode;
    }else{
        struct Node* temp=first;
        while(temp->next!=NULL){
         temp=temp->next;   
        }
        temp->next=newNode;
    }
}

void display(){
    struct Node* t=first;
    printf("The data of the linked list:\n");
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}

void insertion(int key, int pos) {
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=key;
    node->next=NULL;


    if (pos==1) {
        node->next=first;
        first=node;
        return;
    }

    if (first==NULL) {
        printf("Invalid position for empty list.\n");
        free(node);
        return;
    }
    struct Node* temp=first;
    for (int i=0;i<pos-2;i++) {
        temp=temp->next;
        if (temp==NULL) {
            printf("Position out of bound.\n");
            free(node);
            return;
        }
    }
    node->next=temp->next;
    temp->next=node;
}

int deletion(int position){
    if(position<1 || first==NULL){
        return -1;
    }

    struct Node *deleted=first;
    struct Node *beforeDeleted=NULL;
    int deletedValue;

    if(position==1){
        deletedValue=first->data;
        deleted=first;
        first=first->next;
        free(deleted);
    }else{
        deleted=first;
        for(int i=0;i<position-1 && deleted;i++){
            beforeDeleted=deleted;
            deleted=deleted->next;
        }
        deletedValue=deleted->data;
        beforeDeleted->next=deleted->next;
        
        free(deleted);
    }
    return deletedValue;
}

int search(int n){
    struct Node* node=first;
    int c=0;
    while(node){
        if(node->data==n){
            return c+1;
        }
        c++;
        node=node->next;
    }
}

int count(){
    struct Node* temp=first;
    int c=0;
    while(temp){
        c++;
        temp=temp->next;
    }
    return c;
}

int sum(){
    struct Node* temp=first;
    int sum=0;
    while(temp){
        sum+=temp->data;
        temp=temp->next;
    }
    return sum;
}

bool checkSorted(){
    struct Node* node1=first;
    struct Node* node2=first->next;
    while(node2){
        if(node1->data>node2->data){
            return false;
        }
        node1=node1->next;
        node2=node2->next;
    }
    return true;
}

void removeDuplicate(){
    if(!checkSorted()){
        printf("The list is not sorted\n");
    }else{
        struct Node* current=first;
        struct Node* newNode;
        while(current && current->next){
            if(current->data==current->next->data){
                newNode=current->next->next;
                free(current->next);
                current->next=newNode;
            }else{
                current=current->next;
            }
        }
    }
}

void reverse(struct Node* current,struct Node* previous){
    if(current==NULL){
        first=previous;
        return;
    }
    struct Node* nextNode=current->next;
    current->next=previous;
    reverse(nextNode,current);   
}

int main(){
    int num;
    int choice;
    printf("Enter 1 : To create a Linked List\n");
    printf("Enter 2 : To diplay the Linked List\n");
    printf("Enter 3 : To insert in the Linked List\n");
    printf("Enter 4 : To delete an element from the Linked List\n");
    printf("Enter 5 : To search an element from the Linked List\n");
    printf("Enter 6 : To count the number of nodes in the Linked List\n");
    printf("Enter 7 : To calculate the sum of node values in the Linked List\n");
    printf("Enter 8 : To check whether Linked List is sorted\n");
    printf("Enter 9 : To remove duplicate elements in Linked List is sorted\n");
    printf("Enter 10: To reverse elements in Linked List is sorted\n");
    printf("Enter -1: To end operations\n");

    while(choice!=-1){
        printf("Enter choice:");
        scanf("%d",&choice);
        
        if(choice==-1){
            printf("Ending operations......\n");

        }

        if(choice==1){
            int x;
            printf("Enter the number of elements to be entered in the linked list: ");
            scanf("%d",&num);

            printf("Enter the elements: ");
            for(int i=0;i<num;i++){
                scanf("%d",&x);
                insertionLast(x);
            }

            printf("Node successfully created\n");
        }

        if(choice==2) display();

        if(choice==3){
            int x,index;
            printf("Enter the element to be inserted and the insertion index:");
            scanf("%d %d",&x,&index);
            insertion(x,index);
        }

        if(choice==4){
            printf("Enter the position of the element to be deleted: ");
            int pos;
            scanf("%d",&pos);
            printf("Deleted data: %d\n",deletion(pos));

        }

        if(choice==5){
            int x;
            printf("Enter the element to be searched: ");
            scanf("%d",&x);
            printf("The required element is in node: %d\n",search(x));
        }

        if(choice==6){
            printf("The number of nodes in linked list: %d\n",count());
        }

        if(choice==7){
            printf("Then sum of the data in the linked list: %d\n",sum());
        }

        if(choice==8){
            if(checkSorted()){
                printf("The linked list is sorted\n");
            }else{
                printf("The linked list is not sorted\n");
            }
        }

        if(choice==9){
            removeDuplicate();
        }

        if(choice==10){
            reverse(first,NULL);
        }

        printf("--------------------------------------------\n");
    }
    
    return 0;
}
