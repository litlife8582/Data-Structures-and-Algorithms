#include<stdio.h>

int fac(int n){
    if(n==0) return 1;
    else return fac(n-1)*n;
}

int main(){
    printf("%d",fac(5));
}