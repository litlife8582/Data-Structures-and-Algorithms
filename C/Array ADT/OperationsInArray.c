//get(index),set(index,value),maximum(),minnimum(),sum(),avg()

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

int get(int index,struct Array arr){
    return arr.A[index];
}

void set(int index, int value, struct Array *arr){
    arr->A[index]=value;
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

int maximum(struct Array arr){
    int max=arr.A[0];
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]>max) max=arr.A[i];
    }
    return max;
}

int minimum(struct Array arr){
    int min=arr.A[0];
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]<min) min=arr.A[i];
    }
    return min;
}

int sum(struct Array arr){
    int sum=0;
    for(int i=0;i<arr.length;i++){
        sum+=arr.A[i];
    }
    return sum;
}

float avg(struct Array arr){
    return sum(arr)*1.0/arr.length;
}


int main(){
    struct Array arr;
    int n,i;
    printf("Enter the size of the array:");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size*sizeof(int));

    printf("Enter the length of the array:");
    scanf("%d",&arr.length);
    
    printf("Enter the elements of the array:\n");
    for(int i=0;i<arr.length;i++){
        scanf("%d",&arr.A[i]);
    }

    display(arr);

    int index;
    printf("Enter the index of the element to be retrived: ");
    scanf("%d",&index);
    printf("The element at the given index is: %d\n",get(index,arr));

    int value;
    printf("Enter the index and the value to be set in that index:");
    scanf("%d %d",&index,&value);
    set(index,value,&arr);

    printf("The maximum valued element in the array is: %d\n",maximum(arr));
    printf("The minimum valued element in the array is: %d\n",minimum(arr));

    printf("The sum of all elements in the array is:%d\n",sum(arr));
    printf("The avg of all elements in the array is:%.2f\n",avg(arr));
    return 0;
}