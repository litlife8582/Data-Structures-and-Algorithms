#include<stdio.h>
#include<stdlib.h>

void main(){
    int* p=(int* )malloc(5*sizeof(int));
    for(int i=0;i<5;i++){
        scanf("%d",&p[i]);
    }

    for(int i=0;i<5;i++){
        printf("%d\n",p[i]);
    }

    int A[5]={1,2,3,4,5};
    for(int i=0;i<5;i++){
        printf("%d\n",A[i]);
    }

}