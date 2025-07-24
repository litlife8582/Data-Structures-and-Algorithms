#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//iterative step
int partition(int A[],int l,int h){
    int pivot=A[l];
    int i=l,j=h;

    do{
        do{i++;} while(A[i]<=pivot);//exits the loop on finding an element larger than pivot
        //once a element larger than pivot is found to the left it proceeds with the next loop which finds the element which is less than pivot right of the pivot
        do{j--;} while(A[j]>pivot);//exits once an element smaller than pivot is found on the right

        //Swaps the irregular elements
        if(i<j)swap(&A[i],&A[j]);
    }while(i<j);

    swap(&A[l],&A[j]);
    return j;
}


//Recursive part
void QuickSort(int A[],int l,int h){
    int j;
    if(l<h){
        j=partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

int main(){
    int A[]={11,13,7,12,16,9,24,5,10,3,INT_MAX},i;

    QuickSort(A,0,10);

    for(i=0;i<10;i++)
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}