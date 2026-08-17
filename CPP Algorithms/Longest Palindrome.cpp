//Longest Palindrome

#include<iostream>
#include<string>

using namespace std;

void print(string str,int low,int high){
	for(int i=low;i<=high;i++){
		cout<<str[i];
	}
	cout<<endl;
}

int main(){
	string str;

	cin>>str;

	int n=str.length();
	int maxlength=0;
	int start=0;
	int low,high;

	for(int i=0;i<str.length();i++){
		int low=i;
		int high=i;
		while(low>=0 && high<=n && str[low]==str[high]){
			if(high-low+1>maxlength){
				maxlength=high-low+1;
				start=low;
				print(str,start,maxlength+start-1);
			}
			low--;
			high++;
		}
		

		low=i;
		high=i+1;
		while(low>=0 && high<=n && str[low]==str[high]){
			if(high-low+1>maxlength){
				maxlength=high-low+1;
				start=low;
				print(str,start,maxlength+start-1);
			}
			low--;
			high++;
		}
	}

	cout<<"Longest Palindrome: ";
	print(str,start,maxlength+start-1);
	return 0;
}