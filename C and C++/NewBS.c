#include<stdio.h>
#include<stdlib.h>

struct Array{
    int length;
    int size;
    int *A;
};

void sort(struct Array *arr){
    for(int i=0;i<arr->length;i++){
        for(int j=0;j<arr->length-i-1;j++){
            if(arr->A[j]>arr->A[j+1]){
            int temp=arr->A[j+1];
            arr->A[j+1]=arr->A[j];
            arr->A[j]=temp;
            }
        }
    }
}

int binarySearch(struct Array *arr,int element){
    int l=0;
    int h=arr->length-1;
    int mid;
    while(l<=h){
        mid=(l+h)/2;
        if(element==arr->A[mid]) return mid;
        if(element>arr->A[mid]) l=mid+1;
        else h=mid-1;
    }
}

int main(){
    struct Array arr;
    printf("Enter the size: \n");
    scanf("%d",&arr.size);
    arr.A=(int*)malloc(arr.size*sizeof(int));

    printf("Enter the length of the Array:");
    scanf("%d",&arr.length);

    for(int i=0;i<arr.length;i++){
        scanf("%d",&arr.A[i]);
    }

    sort(&arr);
    int e;
    printf("Enter the element to be searched:");
    scanf("%d",&e);

    printf("The element is found in: %d\n",binarySearch(&arr,e));
    free(arr.A);
    return 0;
}