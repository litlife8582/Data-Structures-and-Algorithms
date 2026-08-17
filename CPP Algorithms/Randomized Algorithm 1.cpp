//Randomized Algorithm

#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int>& arr,int low,int high){
	int randIndex = low + rand() % (high - low + 1);
	swap(arr[randIndex],arr[high]);

	int pivot=arr[high];
	int i=low-1;

	for(int j=low;j<high;j++){
		if(arr[i]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
		
	swap(arr[i+1],arr[high]);

	return i+1;
}

void quicksort(vector<int>& arr,int low,int high){
	if(low<high){
		cout<<"pivot: "<<arr[high]<<endl;
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
	
	cout<<"Sorted array:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}