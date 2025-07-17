#include<stdio.h>
#include<stdlib.h>

struct Array{
    int *A;
    int size;
    int length;
};

void display(struct Array arr){
    printf("The elements of the array are: \n");
    for(int i=0;i<arr.length;i++){
        printf("%d\n",arr.A[i]);
    }
}

int main(){
    struct Array arr;
    int n,i;
    printf("Enter the number of elements in the array:");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size*sizeof(int));
    
    printf("Enter the length of the array:");
    scanf("%d",&arr.length);
    
    printf("Enter the elements of the array:\n");
    for(int i=0;i<arr.length;i++){
        scanf("%d",&arr.A[i]);
    }

    display(arr);
    return 0;
}