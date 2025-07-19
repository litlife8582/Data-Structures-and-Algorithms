#include<stdio.h>
#include<stdlib.h>

struct Array{
    int *A;
    int *B;
    int *C;
    int lengthA;
    int lengthB;
    int lengthC;
    int size;
};

void displayA(struct Array arr){
    for(int i=0;i<arr.lengthA;i++){
        printf("%d ",arr.A[i]);
    }
}

void displayB(struct Array arr){
    for(int i=0;i<arr.lengthB;i++){
        printf("%d ",arr.B[i]);
    }
}

void displayC(struct Array arr){
    for(int i=0;i<arr.lengthC;i++){
        printf("%d ",arr.C[i]);
    }
};


void merge(struct Array *arr){
    for(int i=0;i<arr->lengthA;i++){
        arr->C[i]=arr->A[i];
    }
    for(int i=arr->lengthA;i<arr->lengthA+arr->lengthB;i++){
        arr->C[i]=arr->B[i-arr->lengthA];
    }

    // Bubble sort causes o((n+m)^2) time
    // for(int i=0;i<arr->lengthC;i++){
    //     for(int j=0;j<arr->lengthC-i-1;j++){
    //         if(arr->C[j]>arr->C[j+1]){
    //             int temp=arr->C[j+1];
    //             arr->C[j+1]=arr->C[j];
    //             arr->C[j]=temp;
    //         }
    //     }
    // }
}

int main(){
    struct Array arr;

    printf("Enter the size of the arrays: \n");
    scanf("%d",&arr.size);
    arr.A=(int* )malloc(arr.size*sizeof(int));
    arr.B=(int* )malloc(arr.size*sizeof(int));
    arr.C=(int* )malloc(arr.size*sizeof(int));

    printf("Enter the length of the first array: \n");
    scanf("%d",&arr.lengthA);
    
    printf("Enter the elements of the first array:\n");
    for(int i=0;i<arr.lengthA;i++){
        scanf("%d",&arr.A[i]);
    }

    printf("Enter the length of the second array: \n");
    scanf("%d",&arr.lengthB);

    printf("Enter the elements of the second array:\n");
    for(int i=0;i<arr.lengthB;i++){
        scanf("%d",&arr.B[i]);
    }

    // displayA(arr);
    // displayB(arr);

    arr.lengthC= arr.lengthA + arr.lengthB;

    merge(&arr);

    displayC(arr);

    return 0;
}