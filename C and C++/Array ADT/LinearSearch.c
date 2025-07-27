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

void Search(struct Array *arr,int element){
    int index=-1;
    for(int i=0;i<arr->length;i++){
        if(arr->A[i]==element){
            index=i;
        }
    }
    if(index==-1){
        printf("Element not in the array");
    }else{
        printf("Index location of element in the array is: ",index);
    }
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
    int ele;

    printf("Enter the element to be searched: ");
    scanf("%d",&ele);

    Search(&arr,ele);

    return 0;
}