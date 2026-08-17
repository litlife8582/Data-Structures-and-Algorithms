//Randomized Algorithm 2

#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &arr,int low,int high){
	int pivot=arr[low];
	int i=low;

	for(int j=low+1;j<=high;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i],arr[low]);
	return i;
}

void quicksort(vector<int> &arr,int low,int high){
	if(low<high){
		cout<<"Pivot: "<<arr[low]<<endl;
		
		int pi=partition(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}

}

int main(){
	int n;
	cin>>n;

	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	quicksort(arr,0,n-1);
	
	cout<<"Sorted Array:";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}