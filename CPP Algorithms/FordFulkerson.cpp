//FordFulkerson

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int graph[1000][1000];
int rGraph[1000][1000];
int parent[1000];
int visited[1000];

bool bfs(int s,int t, int max_node){
	for(int i=0;i<=max_node;i++){
		visited[i]=false;
	}

	queue<int> q;
	visited[s]=true;
	parent[s]=-1;
	
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		
		for(int v=0;v<=max_node;v++){
			if(!visited[v] && rGraph[u][v]>0){
				if(v==t){
					parent[v]=u;
					return true;
				}
				
				q.push(v);
				parent[v]=u;
				visited[v]=true;
			}
		}		
	}
	
	return false;
}


int fordfulkerson(int s,int t,int max_node){
	for(int u=0;u<=max_node;u++){
		for(int v=0;v<=max_node;v++){
			rGraph[u][v]=graph[u][v];
		}
	}

	int maxflow=0;
	
	while(bfs(s,t,max_node)){
		int pathflow=1e9;
		for(int v=t;v!=s;v=parent[v]){
			int u=parent[v];
			pathflow=min(pathflow,rGraph[u][v]);
		}
	
		for(int v=t;v!=s;v=parent[v]){
			int u=parent[v];
			rGraph[u][v]-=pathflow;
			rGraph[v][u]+=pathflow;
		}
	
		maxflow+=pathflow;
	}
	return maxflow;
}

int main(){
	int n,m;
	if(!(cin>>n>>m)) return 0;
	
	int start,end;
	cin>>start>>end;
	int max_node=max({n,start,end});

	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		graph[u][v]+=w;
		max_node=max({max_node,u,v});
	}
	
	int result=fordfulkerson(start,end,max_node);
	cout<<"Max Flow is: "<<result<<endl;
}