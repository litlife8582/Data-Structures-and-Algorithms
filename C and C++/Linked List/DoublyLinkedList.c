#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}*first=NULL,*last=NULL;

void creation(int x){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    
    if(first==NULL){
        first=newNode;
        last=newNode;
    }else{
        last->next=newNode;
        newNode->prev=last;
        last=newNode;
    }
}

void display(){
    struct Node* temp=first;
    while(temp->next!=NULL && temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void displayReverseOrder(){
    struct Node* temp=last;
    while(temp->prev!=NULL && temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

void insertion(int x, int n){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;

    if(n==1){
        newNode->next=first;
        first->prev=newNode;
        first=newNode;
        return;
    }else{
        struct Node* temp=first;
        for(int i=0;i<n-2;i++){
            temp=temp->next;
            //Incase the index position in invalid
            if(temp==NULL){
                free(newNode);
                return;
            } 
        }
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next=newNode;
        if(newNode->next!=NULL) newNode->next->prev=newNode;    
    }
}

int deletion(int pos){
    //Incase the list is empty or invalid index is provided
    if(pos<1 || first==NULL){
        return -1;
    }
    
    struct Node* deletedNode;
    int x;
    if(pos==1){
        deletedNode=first;
        x=deletedNode->data;
        first=first->next;
        if(first->prev != NULL) first->prev=NULL;
        free(deletedNode);
        return x;
    }

    struct Node* temp=first;
    for(int i=0;i<pos-2;i++){
        temp=temp->next;
        if(temp==NULL){
            printf("Invalid Position!\n");
            return -1;
        }
    }
    if(temp->next=NULL){
        printf("Invalid Position\n");
        return -1;
    }

    
    deletedNode=temp->next;
    x=deletedNode->data;
    temp->next=deletedNode->next;
    
    if(deletedNode->next!=NULL) deletedNode->next->prev=temp;
    free(deletedNode);
    return x;
}

int search(int key){
    struct Node* temp=first;
    int index=1;
    while(temp->next!=NULL && temp!=NULL){
        if(temp->data==key) return index;
        temp=temp->next;
        index++;
    }
    return index;
}

int count(){
    struct Node* count=first;
    int index=0;
    while(count->next!=NULL && count!=NULL){
        count=count->next;
        index++;
    }
    return index; 
}

int sum(){
    struct Node* count=first;
    int s=0;
    while(count->next!=NULL && count!=NULL){
        s+=count->data;
        count=count->next;
    }
    return s;
}


int main(){
    int choice=0;
    int num;
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
    int x;
    while(choice!=-1){
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case -1:
            printf("Ending operations......\n");
        break;

        case 1:
            printf("Enter the number of elements to be entered in the linked list: ");
            scanf("%d",&num);

            printf("Enter the elements: ");
            for(int i=0;i<num;i++){
                scanf("%d",&x);
                creation(x);
            }

            printf("Node successfully created\n");
            break;
        
        case 2:
            display();
        break;

        case 3:
            int x,index;
            printf("Enter the element to be inserted and the insertion index:");
            scanf("%d %d",&x,&index);
            insertion(x,index);
        break;

        case 4:            
            printf("Enter the position of the element to be deleted: ");
            int pos;
            scanf("%d",&pos);
            printf("Deleted data: %d\n",deletion(pos));
        break;

        case 5:
            printf("Enter the element to be searched: ");
            scanf("%d",&x);
            printf("The required element is in node: %d\n",search(x));
        break;

        case 6:
            printf("The number of nodes in linked list: %d\n",count());
        break;
        
        default:
            break;
        }
    }
    return 0;
}