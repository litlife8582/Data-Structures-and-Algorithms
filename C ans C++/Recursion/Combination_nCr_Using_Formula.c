#include<stdio.h>

int fac(int n){
    if(n==0) return 1;
    else return fac(n-1)*n;
}

int C(int n,int r){
    int t1,t2,t3;
    t1=fac(n);
    t2=fac(r);
    t3=fac(n-r);
    return t1/(t2*t3);
}

int main(){
    printf("%d",C(4,3));
    return 0;
}