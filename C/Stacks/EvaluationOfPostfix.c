#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int size;
    int top;
    int* S;
};

void createStack(struct Stack *st,int size){
    st->top=-1;
    st->size=size;
    st->S=(int*)malloc(st->size*sizeof(int));
}

void push(struct Stack *st,int n){
    if(st->top==st->size-1){
        printf("Stack Overflow\n");
    }else{
        st->top++;
        st->S[st->top]=n;
    }
}

int pop(struct Stack *st){
    int x=-1;
    if(st->top<0){
        printf("Stack Underflow\n");
    }else{
        x=st->S[st->top--];
    }
    return x;
}

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/'){
        return 0;
    }else{
        return 1;
    }
}

int evaluate(struct Stack *st,char *postfix){
    int i=0;
    int x1,x2,r;

    for(i=0;postfix[i]!=0;i++){
        if(isOperand(postfix[i]))
            push(st,postfix[i]-'0');
        else{
            x2=pop(st);
            x1=pop(st);

            switch (postfix[i]){
            case '+':
                r=x1+x2;
                break;

            case '-':
                r=x1-x2;
                break;
            
            case '*':
                r=x1*x2;
                break;
            
            case '/':
                r=x1/x2;
                break;
            }
            push(st,r);
        }
    }
    return pop(st);
}

int main(){
    struct Stack s;

    char postfix[100];
    scanf("%s",postfix);

    int stackSize = strlen(postfix) + 2;
    createStack(&s,stackSize);

    printf("%d ",evaluate(&s,postfix));
    return 0;
}