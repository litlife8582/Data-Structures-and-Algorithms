#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;
};

void display(struct Array arr){
    printf("The elements of the array are: \n");
    for(int i=0;i<arr.size;i++){
        printf("%d\n",arr.A[i]);
    }
}

int main(){
    struct Array arr;
    int n,i;
    arr.size=20;
    
    printf("Enter the elements of the array:\n");
    for(int i=0;i<arr.size;i++){
        scanf("%d",&arr.A[i]);
    }

    display(arr);
    return 0;
}