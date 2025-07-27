#include<stdio.h>
#include<stdlib.h>

struct Array{
    int *A;
    int length;
    int size;
};

void display(struct Array arr){
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
}

int checkSorted(struct Array arr){
    for(int i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1]) return 0;
        else return 1;
    }
}

void sorted(struct Array *arr){
    for(int i=0;i<arr->length;i++){
        for(int j=0;j<arr->length-i-1;j++){
            int temp=arr->A[j+1];
            arr->A[j+1]=arr->A[j];
            arr->A[j]=temp;
        }
    }
}

void insertion(struct Array *arr,int n){
    int index=0;
    for(int i=0;i<arr->length;i++){
        if(n<arr->A[i]){
            index=i;
            break;
        }
    }

    arr->length++;

    for(int i=arr->length;i>index;i--){
        arr->A[i]=arr->A[i-1];
    }

    arr->A[index]=n;
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
    
    if(checkSorted(arr)==1){
        printf("Array sorted\n");
    }else{
        printf("Array not sorted\n");
        sorted(&arr);
        printf("Sorted Array:\n");
        display;
    }

    int num;
    printf("Enter the element to be inserted: ");
    scanf("%d",&num);

    insertion(&arr,num);

    display(arr);

    return 0;
}