#include<stdio.h>
#include<stdlib.h>

struct Array{
    int *A;
    int size;
    int length;
};

int binarySearch(struct Array arr, int element){
    int low=0,high=arr.length-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr.A[mid]==element){
            return mid;
        }else if(arr.A[mid]>element){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return -1;
}

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

void display(struct Array arr){
    for(int i=0;i<arr.length;i++){
        printf("%d\n",arr.A[i]);
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

    sort(&arr);

    display(arr);
    int ele;

    printf("Enter the element to be searched: ");
    scanf("%d",&ele);

    printf("The index of the given element is: %d\n",binarySearch(arr,ele));

    return 0;
}