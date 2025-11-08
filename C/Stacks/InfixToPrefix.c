#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
    int size;
    int top;
    char* S;
};

void createStack(struct Stack *st, int size){
    st->top = -1;
    st->size = size;
    st->S = (char*)malloc(st->size * sizeof(char));
}

void push(struct Stack *st, char n){
    if (st->top == st->size - 1){
        printf("Stack Overflow\n");
    } else {
        st->S[++st->top] = n;
    }
}

char pop(struct Stack *st){
    if (st->top == -1){
        // printf("Stack Underflow\n");
        return -1;
    } else {
        return st->S[st->top--];
    }
}

char peek(struct Stack *st){
    if (st->top == -1)
        return -1;
    return st->S[st->top];
}

int isOperator(char x){
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

int precedence(char x){
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else
        return 0;
}

void reverseString(char *exp){
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++){
        char temp = exp[i];
        exp[i] = exp[len - 1 - i];
        exp[len - 1 - i] = temp;
    }
}

void swapParentheses(char *exp){
    for (int i = 0; exp[i] != '\0'; i++){
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
}

char* infixToPostfix(char *infix){
    int len = strlen(infix);
    char* postfix = (char*)malloc((len + 1) * sizeof(char));
    struct Stack st;
    createStack(&st, len + 10);
    
    int i = 0, j = 0;
    while (infix[i] != '\0'){
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9')){
            // operand
            postfix[j++] = infix[i++];
        } else if (infix[i] == '('){
            push(&st, '(');
            i++;
        } else if (infix[i] == ')'){
            while (peek(&st) != '(' && st.top != -1)
                postfix[j++] = pop(&st);
            pop(&st); // pop '('
            i++;
        } else if (isOperator(infix[i])){
            while (st.top != -1 && precedence(peek(&st)) >= precedence(infix[i]))
                postfix[j++] = pop(&st);
            push(&st, infix[i]);
            i++;
        } else {
            i++;
        }
    }
    
    while (st.top != -1){
        postfix[j++] = pop(&st);
    }
    postfix[j] = '\0';
    free(st.S);
    return postfix;
}

char* infixToPrefix(char *infix){
    int len = strlen(infix);
    char *reversedInfix = (char*)malloc((len + 1) * sizeof(char));
    strcpy(reversedInfix, infix);
    reverseString(reversedInfix);

    swapParentheses(reversedInfix);

    char *postfix = infixToPostfix(reversedInfix);

    int postfixLen = strlen(postfix);
    char *prefix = (char*)malloc((postfixLen + 1) * sizeof(char));
    strcpy(prefix, postfix);
    reverseString(prefix);

    free(reversedInfix);
    free(postfix);

    return prefix;
}

int main(){
    char infix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    char *prefix = infixToPrefix(infix);

    printf("Prefix expression: %s\n", prefix);

    free(prefix);

    return 0;
}
