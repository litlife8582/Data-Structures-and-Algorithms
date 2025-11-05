#include "queue.h"
#include<stdio.h>

#define N 7
int G[N][N] = {
      /*      1  2  3  4  5  6  7  */
      /*1*/{0, 1, 1, 0, 0, 0, 0},
      /*2*/{1, 0, 0, 1, 1, 0, 0},
      /*3*/{1, 0, 0, 0, 0, 1, 1},
      /*4*/{0, 1, 0, 0, 1, 0, 0},
      /*5*/{0, 1, 0, 1, 0, 0, 0},
      /*6*/{0, 0, 1, 0, 0, 0, 0},
      /*7*/{0, 0, 1, 0, 0, 0, 0}
};


//prints the adjacency matrix
void display(){
      printf("  ");
      for (int i=0;i<N;i++) {
            printf("%d ",i+1);//printing x-axis
      }
      printf("\n");
      printf("  ");
      for (int i=0;i<N;i++) {
            printf("- ",i+1);
      }
      printf("\n");
      for (int i=0;i<N;i++) {
            printf("%d|",i+1);//printing y-axis
            for (int j=0;j<N;j++)
                  printf("%d ",G[i][j]);
            printf("\n");
      }

}

//BFS, key->starting vertex
void BFS(int key) {
      struct Queue q;
      create(&q,7);
      printf("%d ",key);
      int startIndex=key-1;//this is done so that the 0-6 based index can be made 1-7 based index for the user
      int visited[N]={0};
      visited[startIndex]=1;
      enqueue(&q,startIndex);
      while (!isEmpty(&q)) {
            int u=dequeue(&q);
            for (int v=0;v<N;v++) {
                  if (G[u][v]==1 && visited[v]==0) {
                        printf("%d ",v+1);
                        visited[v]=1;
                        enqueue(&q,v);
                  }
            }
      }
}

int visited[N]={0};
void DFS(int key) {
      visited[key]=1;
      printf("%d ",key+1);
      for (int u=0;u<N;++u) {
            if (G[key][u] && !visited[u]) {
                  DFS(u);
            }
      }
}

int main(){
      display();
      printf("\n");
      BFS(2);
      printf("\n");
      DFS(1);
}