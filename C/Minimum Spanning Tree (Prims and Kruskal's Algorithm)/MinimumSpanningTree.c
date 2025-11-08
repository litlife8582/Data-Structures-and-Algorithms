#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define N 6
int G[N][N] = {
    /*      1  2  3  4  5  6  */
    /*1*/{0, 4, 2, 0, 0, 0},
    /*2*/{4, 0, 1, 5, 0, 0},
    /*3*/{2, 1, 0, 8,10, 0},
    /*4*/{0, 5, 8, 0, 2, 6},
    /*5*/{0, 0,10, 2, 0, 3},
    /*6*/{0, 0, 0, 6, 3, 0}
};

void display() {
    printf("   ");
    for (int i=0;i<N;i++) {
        printf("%d ",i+1);
    }
    printf("\n");
    printf("   ");
    for (int i=0;i<N;i++) {
        printf("- ");
    }
    printf("\n");
    for (int i=0;i<N;i++) {
        printf("%d |",i+1);
        for (int j=0;j<N;j++) {
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
}

/*--------------------------------------------Prim's Algorithm---------------------------------------------*/

//Finds vertex with minimum key value from the set of vertices
int minKey(int key[],bool mstSet[]) {
    int min=INT_MAX,min_index;
    for (int v=0;v<N;v++) {
        if (mstSet[v]==false &&key[v]<min) min=key[v],min_index=v;
    }
    return min_index;
}

int printMST(int parent[],int graph[N][N]) {
    printf("Edge \tWeight\n");
    for (int i=1;i<N;i++) {
        printf("%d - %d \t%d \n",parent[i],i,graph[parent[i]][i]);
    }
}

void primMST(int graph[N][N]) {
    int parent[N];
    int key[N];
    bool mstSet[N];

    for (int i=0;i<N;i++)
        key[i]=INT_MAX,mstSet[i]=false;

    key[0]=0;
    parent[0]=-1;

    for (int count =0;count<N-1;count++) {
        int u=minKey(key,mstSet);
        mstSet[u]=true;
        for (int v=0;v<N;v++)
            if (graph[u][v] && mstSet[v]==false && graph[u][v]<key[v])
                parent[v]=u,key[v]=graph[u][v];
    }
    printMST(parent,graph);
}


/*-----------------------------------------------Kruskal's Algorithm--------------------------------------*/
int comparator(const void* p1, const void* p2)
{
    const int* a = *(const int(*)[3])p1;
    const int* b = *(const int(*)[3])p2;
    return a[2] - b[2];
}

void makeSet(int parent[], int rank[], int n)
{
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component)
{
    if (parent[component] == component)
        return component;

    return parent[component]
           = findParent(parent, parent[component]);
}

void unionSet(int u, int v, int parent[], int rank[])
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int kruskalAlgo(int V, int E, int edge[E][3])
{
    qsort(edge, E, sizeof(edge[0]), comparator);

    int* parent = (int*)malloc(V * sizeof(int));
    int* rank = (int*)malloc(V * sizeof(int));

    makeSet(parent, rank, V);

    int minCost = 0;
    printf("Edge \tWeight\n");

    for (int i = 0; i < E; i++) {
        int v1 = findParent(parent, edge[i][0]);
        int v2 = findParent(parent, edge[i][1]);
        int wt = edge[i][2];

        if (v1 != v2) {
            unionSet(v1, v2, parent, rank);
            minCost += wt;
            printf("%d - %d \t%d \n", edge[i][0], edge[i][1], wt);
        }
    }

    free(parent);
    free(rank);

    return minCost;
}

int main() {
    display();
    primMST(G);
    int edgeCount = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(G[i][j] != 0) {
                edgeCount++;
            }
        }
    }

    int (*edgeList)[3] = malloc(edgeCount * sizeof(*edgeList));

    int k = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(G[i][j] != 0) {
                edgeList[k][0] = i;
                edgeList[k][1] = j;
                edgeList[k][2] = G[i][j];
                k++;
            }
        }
    }

    int minCost = kruskalAlgo(N, edgeCount, edgeList);
    printf("Minimum Cost: %d\n", minCost);

    free(edgeList);

    return 0;
}