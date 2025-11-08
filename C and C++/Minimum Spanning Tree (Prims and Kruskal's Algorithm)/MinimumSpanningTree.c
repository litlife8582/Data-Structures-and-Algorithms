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

int main() {
    display();
    primMST(G);
    return 0;
}