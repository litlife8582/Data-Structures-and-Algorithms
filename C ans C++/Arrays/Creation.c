#include<stdio.h>

int main(){
    int A[5];
    int B[5]={1,2,3,4,5};
    int C[10]={2,4,6};
    int D[5]={0};
    int E[]={2,4,6,8};
    for(int i=0;i<5;i++) printf("%d\n",A[i]);
    printf("\n");
    for(int i=0;i<5;i++) printf("%d\n",B[i]);
    printf("\n");
    for(int i=0;i<10;i++) printf("%d\n",C[i]);
    printf("\n");
    for(int i=0;i<5;i++) printf("%d\n",D[i]);
    printf("\n");
    for(int i=0;i<5;i++) printf("%d\n",E[i]);
    printf("\n");
    return 0;
}