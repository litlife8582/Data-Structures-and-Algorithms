#include<stdio.h>
#include<stdlib.h>


void Merge(int A[],int l,int m, int h){
    int i=l,j=m+1,k=l;
    int C[100];
    while(i<=m && j<=h){
        if(A[i]<A[j])//Compares the indexes of the arrays to check which has smaller element
            C[k++]=A[i++];//If ith index is smaller than jth index it's element will be addded to a new array
        else
            C[k++]=A[j++];//Otherwise jth index element will be added
    }//this looping ends when all element of the smaller half is compared and added
    
    //Now we add the remaining elements of the larger array.
    //We run loop for both halfs whichever half has remaining elements add and the other one remains unchanged
    for(;i<=m;i++){
        C[k++]=A[i];
    }
    for(;j<=h;j++){
        C[k++]=A[j];
    }

    //We copy the sorted array into the original array
    for(int i=l;i<=h;i++){
        A[i]=C[i];
    }
}

void MergeSort(int A[],int l,int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

int main(){
    int A[]={2,5,3,1,6,8,7,9,10,11};
    int n=sizeof(A)/sizeof(A[0]);
    MergeSort(A,0,n-1);
    for(int i=0;i<10;i++){
        printf("%d ",A[i]);
    }
    return 0;
}
