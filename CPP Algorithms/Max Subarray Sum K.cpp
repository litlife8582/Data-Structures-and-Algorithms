//Max Subarray Sum K

#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

long long midpointcross(vector<int> &A,int low, int mid,int high,int k){
	long long maxsum=LLONG_MIN;
	int start=max(low,mid-k+1);
	int end=min(mid,high-k+1);
	
	for(int i=start;i<=end;i++){
		long long currentSum=0;
		for(int j=0;j<k;j++){
			currentSum+=A[i+j];
		}
		
		if(currentSum>maxsum){
			maxsum=currentSum;
		}
	}
	return maxsum;	
}

long long maxSubarray(vector<int> &A,int low,int high,int k){
	if(high-low+1<k) return LLONG_MIN;
	
	if(high-low+1==k){
		long long sum=0;
		for(int i=low;i<=high;i++){
			sum+=A[i];
		}
		return sum;
	}	
	
	int mid=(high+low)/2;
	long long lsum=maxSubarray(A,low,mid,k);
	long long csum=midpointcross(A,low,mid,high,k);
	long long rsum=maxSubarray(A,mid+1,high,k);
	
	return max({lsum,csum,rsum});
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> A(n);

	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	
	long long maxsum=maxSubarray(A,0,n-1,k);
	cout<<"Maximum Sum: "<<maxsum<<endl;

	return 0;
}