#include<iostream>
using namespace std;

int main(){
    int *A=new int[5];
    int *B=new int[10];

    for(int i=0;i<5;i++){
        A[i]=i+1;
    }

    for(int i=0;i<5;i++){
        B[i]=A[i];
    }

    delete[] A;

    A=B;

    B=NULL;

    for(int i=0;i<10;i++){
        cout<<A[i]<<endl;
    }

    return 0;
}