#include<stdio.h>
#include<stdlib.h>


struct Array{
    int *A;
    int *B;
    int size;
    int length;
};

void display(struct Array *arr){
    printf("The elements of the array are: \n");
    for(int i=0;i<arr->length;i++){
        printf("%d\n",arr->A[i]);
    }
}

void reverse(struct Array *arr){
    int j=arr->length-1;
    for(int i=0;i<arr->length;i++){
       arr->B[j]=arr->A[i];
       j--;
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

    display(&arr);

    reverse(&arr);
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.B[i]);
    }
    return 0;
}