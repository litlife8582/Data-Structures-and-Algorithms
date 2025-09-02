#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int count(struct Node* p){
    int l=0;
    while (p){
        l++;
        p=p->next;
    }
    return l;
}

//Recursive Count
int Rcount(struct Node *p){
    if(p)
        return Rcount(p->next)+1;
    else
        return 0;
}

int sum(struct Node *p){
    int s=0;
    while(p!=NULL){
        s+=p->data;
        p=p->next;
    }
    return s;
}

//Recursive Sum
int Rsum(struct Node *p){
    if(p==NULL)
        return 0;
    else 
        return Rsum(p->next)+p->data;
}

int main(){
    int A[]={3,5,7,10,15,90};
    create(A,3);
    printf("Length is %d\n\n",Rcount(first));//returns the value of length passed in q irrespective of whether there is any element
    printf("Sum is: %d",Rsum(first));
    return 0;
}