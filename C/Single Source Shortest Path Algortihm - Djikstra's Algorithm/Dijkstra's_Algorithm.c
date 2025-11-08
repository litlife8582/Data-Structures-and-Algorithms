#include<stdio.h>
#include<limits.h>

#define MAX 100
#define INF INT_MAX

int main() {
    int n,src;
    int G[MAX][MAX];
    int visited[MAX];
    int parent[MAX];
    int dist[MAX];

    //-------------------------------------Input-------------------------------------------
    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    printf("Enter the edges in the adjacency matrix.(Enter 0 for no edge): ");
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            scanf("%d",&G[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d",&src);

    //-----------------------------------------Initialization----------------------------------------------
    for (int i=0;i<n;i++) {
        visited[i]=0;
        dist[i]=INF;
        parent[i]=-1;
    }
    dist[src]=0;

    //------------------------------------Dijkstra's Algorithm---------------------------------
    for (int count=0;count<n-1;count++) {
        int u=-1,best=INF;
        for (int i=0;i<n;i++) {
            if (!visited[i] && dist[i]<best) {
                u=i;
                best=dist[i];
            }
        }

        if (u==-1) break;
        visited[u]=1;

        for (int v=0;v<n;v++) {
            if (!visited[v] && G[u][v]!=0 && dist[u]!=INF) {
                int nd=dist[u]+G[u][v];
                if (nd<dist[v]) {
                    dist[v]=nd;
                    parent[v]=u;
                }
            }
        }
    }

    //---------------------------------------Output-------------------------------------------
    printf("\n Shortest distance from source %d: \n",src);
    for (int i=0;i<n;i++) {
        if (dist[i]==INF) printf("to %d: INF\n",i);
        else printf("to %d: %d\n",i,dist[i]);
    }

    printf("\nPaths:\n");
    for (int i=0;i<n;i++) {
        if (dist[i] == INF) { printf("%d: no path\n", i); continue; }
        int path[MAX],len=0,cur=i;
        while (cur!=-1) {
            path[len++]=cur;
            cur=parent[cur];
        }

        printf("%d: ",i);
        for (int j=len-1;j>=0;j--) {
            printf("%d",path[j]);
            if (j) printf(" -> ");
        }

        printf("\nCost = %d\n",dist[i]);
    }



    return 0;
}