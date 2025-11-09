#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int Partition(int arr[], int l, int h) {
    int pivot = arr[l];
    int i = l - 1;
    int j = h + 1;

    while (1) {
        do{i++;} while (arr[i] < pivot);
        do{j--;} while (arr[j] > pivot);
        if (i >= j) return j;// j is the point where the pivot currently is
        swap(&arr[i], &arr[j]);
    }
}

void QuickSort(int A[], int l, int h){
    int j;
    if(l<h){
        j=Partition(A,l,h);//THe pivot is returned and the array is divided from the pivot
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

int main(){
    int A[]={1,4,2,5,7,3,9,8,7,10};
    int size=sizeof(A)/sizeof(A[0]);
    QuickSort(A,0,size);
    for(int i=0;i<size;i++){
        printf("%d ",A[i]);
    }
}
