//Vector Cover

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
		
	vector<pair<int,int>> edges(m);
	for(int i=0;i<m;i++){
		cin>>edges[i].first>>edges[i].second;
	}
	
	vector<bool> visited(n+1,false);
	vector<int> cover;
	
	for(int i=0;i<m;i++){
		int u=edges[i].first;
		int v=edges[i].second;

		if(!visited[u] && !visited[v]){
			visited[u]=true;
			visited[v]=true;
			cover.push_back(u);
			cover.push_back(v);
		}
	}

	sort(cover.begin(),cover.end());
	cout<<"The required Vertex cover is as follows: "<<endl;
	for(int i=0;i<cover.size();i++){
		cout<<cover[i]<<" ";
	}
	return 0;
}