#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
    int size;
    int top;
    char *S;
};

void create(struct Stack *st,int size){
    st->size=size;
    st->S=(char *)malloc(st->size*sizeof(char));
    st->top=-1;
} 

void push(struct Stack *st,char x){
    if(st->top==st->size){
        printf("Stack is full");
    }else{
        st->top++;
        st->S[st->top]=x;
    }
}

int pop(struct Stack *st){
    int x=-1;
    if(st->top<0){
        printf("Stack is empty");
    }else{
        x=st->S[st->top--];
    }
    return x;
}

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    else 
        return 1;
}

int pre(char x){
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    else 
        return 0;
}

char* convert(struct Stack *st,char *infix){
    char* postfix=(char *)malloc((strlen(infix)+2)*sizeof(char));
    int i,j;

    i=j=0;

    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
           postfix[j++]=infix[i++];
        }else{
            if(pre(infix[i])>pre(st->S[st->top])){
                push(st,infix[i++]);
            }else{
                postfix[j++]=pop(st);
            }
        }
    }

    while(st->top!=0)
        postfix[j++]=pop(st);
    postfix[j]='\0';

    return postfix;
}

int main(){
    struct Stack st;
    

    char* infix;
    scanf("%s",infix);
    

    int strsize=strlen(infix);
    create(&st,strsize);

    push(&st,'#');
    printf("%s",convert(&st,infix));
    return 0;
    
}
