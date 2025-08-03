#include<stdio.h>
#include<stdlib.h>

struct Stack{
	int size;
	int top;
	int *S;
};

void create(struct Stack *st){
	printf("Enter the size of the Stack:");
	scanf("%d",&st->size);
	st->top=-1;
	st->S=(int*)malloc(st->size*sizeof(int));
}

void display(struct Stack st){
	for(int i=st.top;i>=0;i--){
		printf("%d ",st.S[i]);
	}
	printf("\n");
}

void push(struct Stack *st,int x){
	if(st->top==st->size-1){
		printf("Stack Overflow\n");
	}else{
		st->top++;
		st->S[st->top]=x;
	}
}

int pop(struct Stack *st){
	if(st->top==-1){
		printf("Stack Underflow\n");
		return -1;
	}else{
		return st->S[st->top--];
	}
}

int peek(struct Stack st, int index){
	int x=-1;
	if(st.top-index++<0){
		printf("Invalid Index\n");
	}
	x=st.S[st.top-index+1];
	
	return x;
}

int main(){
	struct Stack st;

	create(&st);
	
	int n;

	for(int i=0;i<st.size;i++){
		scanf("%d",&n);
		push(&st,n);
	}

	display(st);
	
	int p=0;
	while (st.top != -1) {
		int x = pop(&st);
		printf("Popped: %d\n", x);
		display(st);
	}	

	int index;
	scanf("%d",&index);

	printf("%d",peek(st,index));	
	return 0;
}