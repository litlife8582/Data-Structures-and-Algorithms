//Max Subarray Sum

#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<climits>

using namespace std;

tuple<long long,int,int> midpointCross(vector<int> &A,int low,int mid,int high,long long limit){
	long long maxSum=LLONG_MIN;
	int start=-1,end=-1;

	long long currentLeftSum=0;
	for(int i=mid;i>=0;i--){
		currentLeftSum+=A[i];

		long long currentRightSum=0;
		for(int j=mid+1;j<=high;j++){
			currentRightSum+=A[j];

			long long totalSum=currentLeftSum+currentRightSum;
			if(totalSum<=limit){
				if(totalSum>maxSum){
					maxSum=totalSum;
					start=i;
					end=j;
				}else if(totalSum==maxSum){
					start=i;
					end=j;
				}
			}
		}
	}

	return {maxSum,start,end};
}

tuple<long long,int,int> maxSubarray(vector<int> &A,int low,int high,long long limit){
	if(low>=high){
		if(A[low]<=limit) return {A[low],low,high};
		return {LLONG_MIN,-1,-1}; 
	}

	int mid=(high+low)/2;
	auto[lsum,lstart,lend]=maxSubarray(A,low,mid,limit);
	auto[csum,cstart,cend]=midpointCross(A,low,mid,high,limit);
	auto[rsum,rstart,rend]=maxSubarray(A,mid+1,high,limit);
	
	long long maxSum=LLONG_MIN;
	int start=-1,end=-1;
	
	if(lsum>maxSum){
		maxSum=lsum;
		start=lstart;
		end=lend;
	}
	
	if(csum>maxSum){
		maxSum=csum;
		start=cstart;
		end=cend;
	}
	
	if(rsum>maxSum){
		maxSum=rsum;
		start=rstart;
		end=rend;
	}
		
	return {maxSum,start,end};
}

int main(){
	int n;
	long long limit;
	
	cin>>n>>limit;
		
	vector<int> A(n);
	
	for(int i=0;i<n;i++){
		cin>>A[i];		
	}
	
	auto[sum,start,end]=maxSubarray(A,0,n-1,limit);
	cout<<start+1<<" "<<end+1<<endl;
	return 0;
}