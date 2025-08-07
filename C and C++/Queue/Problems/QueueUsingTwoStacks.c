#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int* S;
};

void createQueue(struct Stack *s,int size){
    s->size=size;
    s->S=(int*)malloc(s->size*sizeof(int));
    s->top=-1;
}

void push(struct Stack *s,int x){
    if(s->top==s->size)
        printf("Stack is full");
    else{
        s->top++;
        s->S[s->top]=x;
    }
}

int pop(struct Stack *s){
    int x=-1;
    if(s->top==-1)
        printF("The stack is empty");
    else{
        s->top--;
        x=s->S[s->top];
    }
    return x;
}

void enqueue(struct Stack *a,int x){
    push(a,x);
}

void dequeue(struct Stack *a,struct Stack *b){
    int x=pop(a);
    push(b,x);
}

int main(){
    struct Stack s1,s2;
    
    int size;
    printf("Enter the size of the queue: ");
    scanf("%d",&size);

    createStack(s1,size);
    createStack(s2,size);


    
    return 0;
}
