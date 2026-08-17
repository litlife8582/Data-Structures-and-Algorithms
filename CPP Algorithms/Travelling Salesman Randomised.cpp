//Travelling Salesman

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int n;
int mincost=INT_MAX;
vector<vector<int>> matrix;
vector<bool> visited;

void tsp(int u,int count,int currentCost){
	if(count==n){	
		mincost=min(mincost,currentCost+matrix[u][0]);
		return;
	}

	for(int v=0;v<n;v++){
		if(!visited[v]){
			visited[v]=true;
			tsp(v,count+1,currentCost+matrix[u][v]);
			visited[v]=false;
		}
	}
}

int main(){
	cin>>n;
	matrix.assign(n,vector<int> (n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>matrix[i][j];
		}
	}

	visited.assign(n,false);
	visited[0]=true;
	
	tsp(0,1,0);
	cout<<"Minimum cost: "<<mincost<<endl;
	return 0;
}