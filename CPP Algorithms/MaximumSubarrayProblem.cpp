#include<iostream>
#include<array>
#include<cmath>
#include<algorithm>
#include<climits>

using namespace std;

int maximum(int a,int b, int c) {
    return max({a,b,c});
}

long long midpointCross(int A[],int low,int mid,int high) {
    int sum=0;
    long long rightSum=LLONG_MIN;
    long long leftSum=LLONG_MIN;
    for (int i=mid;i>=low;i--) {
        sum+=A[i];
        if (sum> leftSum) leftSum=sum;
    }
    sum=0;
    for (int i=mid+1;i<=high;i++) {
        sum+=A[i];
        if (sum>rightSum) rightSum=sum;
    }
    return leftSum+rightSum;
}

long long LeftRightMaximumSubarray(int A[],int low,int high) {
    if (high==low) return A[low];
    int mid=(low+high)/2;
    long long leftSum=LeftRightMaximumSubarray(A,low,mid);
    long long rightSum=LeftRightMaximumSubarray(A,mid+1,high);
    long long midcrosssum=midpointCross(A,low,mid,high);
    return maximum(leftSum,rightSum,midcrosssum);
}

int main() {
    int n;
    int A[100];
    cin>>n;

    for (int i =0;i<n;i++) {
        cin>>A[i];
    }
    cout<<"The maximum subarray: "<<LeftRightMaximumSubarray(A,0,n-1);
    return 0;
}
