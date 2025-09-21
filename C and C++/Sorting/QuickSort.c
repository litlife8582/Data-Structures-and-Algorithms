#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int arr[],int l,int h){
    int pivot=arr[l];
    int i=l,j=h;
    do{
        do{i++;}while(arr[i]<=pivot);
        do{j--;}while(arr[j]>pivot);
        if(i<j) swap(&arr[i],&arr[j]);
    }while(i<j);
    swap(&arr[l],&arr[j]);
    return j;
}

void QuickSort(int arr[],int l,int h){
    int j;
    if(l<h){
        j=partition(arr,l,h);
        QuickSort(arr,l,j);
        QuickSort(arr,j+1,h);
    }
}

int main(){
    int A[]={11,13,7,12,16,9,24,5,10,3},i;

    QuickSort(A,0,10);

    for(i=0;i<10;i++)
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}