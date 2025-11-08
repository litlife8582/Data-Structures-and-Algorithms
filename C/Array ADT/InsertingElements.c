#include<stdio.h>
#include<stdlib.h>

struct Array{
    int *A;
    int size;
    int length;
};

void display(struct Array arr){
    for(int i=0;i<arr.length;i++){
        printf("%d\n",arr.A[i]);
    }
}

void insert(int index,int ele,struct Array *arr){
    for(int i=arr->length;i>index;i--){
        arr->A[i]=arr->A[i-1];
    }

    arr->A[index]=ele;
    arr->length++;

    display(*arr);
}

int main(){
    struct Array arr;
    printf("Enter the size of the array: \n");
    scanf("%d",&arr.size);
    arr.A=(int* )malloc(arr.size*sizeof(int));

    printf("Enter the length of the array: \n");
    scanf("%d",&arr.length);
    
    printf("Enter the elements:\n");
    for(int i=0;i<arr.length;i++){
        scanf("%d",&arr.A[i]);
    }

    display(arr);
    int ele,index;

    printf("Enter the index and element to be inserted: ");
    scanf("%d %d",&index,&ele);

    insert(index,ele,&arr);

    return 0;
}