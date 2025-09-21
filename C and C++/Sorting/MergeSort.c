#include<stdio.h>
#include<stdlib.h>


void Merge(int A[],int l,int m, int h){
    int i=l,j=m+1,k=l;
    int C[100];
    while(i<=m && j<=h){
        if(A[i]<A[j])
            C[k++]=A[i++];
        else
            C[k++]=A[j++];
    }
    for(;i<=m;i++){
        C[k++]=A[i];
    }
    for(;j<=h;j++){
        C[k++]=A[j];
    }
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