#include<stdio.h>
#include<stdlib.h>

struct Array{
    int *A;
    int *B;
    int length;
    int size;
};

void display(struct Array arr){
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }

    printf("\n");

    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.B[i]);
    }
}

void shift(struct Array *arr,int k){
     k=k%arr->length;

    int j=0;

    for(int i=k; i<arr->length; i++){
        arr->B[j++] = arr->A[i];
    }

    
    for(int i=0;i<k;i++){
        arr->B[j++]=arr->A[i];
    }
}

int main(){
    struct Array arr;
    printf("Enter the size of the array: \n");
    scanf("%d",&arr.size);
    arr.A=(int* )malloc(arr.size*sizeof(int));
    arr.B=(int* )malloc(arr.size*sizeof(int));

    printf("Enter the length of the array: \n");
    scanf("%d",&arr.length);
    
    printf("Enter the elements:\n");
    for(int i=0;i<arr.length;i++){
        scanf("%d",&arr.A[i]);
    }


    int num;
    printf("Enter the number of places to shift the elements in the array: ");
    scanf("%d",&num);

    shift(&arr,num);
    
    display(arr);
    return 0;
}