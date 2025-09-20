//Stack: Implement Push, Pop, Peek/Top element, IsEmpty, and IsFull operations.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Stack{
    int *S;
    int size;
    int top;
};

bool isEmpty(struct Stack *st){
    if(st->top==-1){
        return true;
    }
    return false;
}

bool isFull(struct Stack *st){
    if(st->top==st->size-1){
        return true;
    }
    return false;
}

void create(struct Stack *st){
    printf("Enter the size of the stack:");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}

void push(struct Stack *st,int x){
    if(st->top!=st->size-1){
        st->top++;
        st->S[st->top]=x;
    }else{
        printf("Stack Overflow\n");
    }
}

int pop(struct Stack *st){
    int x=-1;
    if(st->top!=-1){
        x=st->S[st->top];
        st->top--;
    }else{
        printf("Stack underflow\n");
    }
    return x;
}

int display(struct Stack *st){
    for(int i=st->top;i>-1;i--){
        printf("%d ",st->S[i]);
    }
    printf("\n");
}

int peek(struct Stack *st){
    return st->S[st->top];
}

int main(){
    struct Stack *st;
    printf("Menu:\n");
    printf("1.Create\n");
    printf("2.Push\n");
    printf("3.Pop\n");
    printf("4.Display\n");
    printf("5.isEmpty\n");
    printf("6.isFull\n");
    printf("7.Peek\n");
    int choice;
    do{
        printf("Choice: \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            create(st);
            break;

            case 2:
            printf("Enter the data to be pushed:\n");
            int data;
            scanf("%d",&data);
            push(st,data);
            break;

            case 3:
            printf("Popped data: %d\n",pop(st));
            break;

            case 4:
            display(st);
            break;

            case 5:
            (isEmpty(st))?printf("The stack is empty\n"):printf("The stack is not empty\n");
            break;

            case 6:
            (isFull(st))?printf("The stack is full\n"):printf("The stack is not full\n");
            break;
            
            case 7:
            printf("Top value: %d\n",peek(st));
            break;

            default:
            printf("Invalid input\n");
        }
    }while(choice!=0);
    return 0;
}
