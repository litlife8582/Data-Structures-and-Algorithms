#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int size;
    int top;
    char* S;
};

void createStack(struct Stack *st,int size){
    st->top=-1;
    st->size=size;
    st->S=(char*)malloc(st->size*sizeof(char));
}

void push(struct Stack *st,char n){
    if(st->top==st->size-1){
        printf("Stack Overflow\n");
    }else{
        st->top++;
        st->S[st->top]=n;
    }
}

char pop(struct Stack *st){
    char x=-1;
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

int pre(char x){
    if(x=='+' || x=='-') return 1;
    else if(x=='*' || x=='/') return 2;
    return 0;
}

char* convert(struct Stack *st,char* infix){
    char* postfix=(char* )malloc((strlen(infix)+2)*sizeof(char));
    int i,j;
    i=j=0;

    while(infix[i]!='\0'){
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else{
            if(pre(infix[i])>pre(st->S[st->top]))
                push(st,infix[i++]);
            else{
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
    struct Stack s;
    // char *infix="a+b+c";

    char *infix;
    scanf("%s",infix);

    int stackSize = strlen(infix) + 2;
    createStack(&s,stackSize);
    
    push(&s,'#');

    char *postfix=convert(&s,infix);

    printf("%s ",postfix);
    return 0;
}