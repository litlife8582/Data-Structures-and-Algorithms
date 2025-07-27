#include<stdio.h>

int Linear_Search(int n,int *A){
int index=-1;
for(int i=0;i<n;i++){
if(A[i]==n){
index=i+1;
break;
}
}
return index;
}

int main(){
int num,target;
scanf("%d",&num);
scanf("%d",&target);
int Arr[100];
for(int i=0;i<num;i++){
scanf("%d",&Arr[i]);
}
printf("%d",Linear_Search(target,Arr));
return 0;
}