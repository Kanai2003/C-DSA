#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

void bfs(int graph[][MAX_VERTICES], int n, int start)
{
	int visited[MAX_VERTICES] = {0};
	int queue[MAX_VERTICES];
	int front = -1, rear = -1;
   
	queue[++rear] = start;
	visited[start] = 1;
   
	printf("BFS traversal: ");
	while(front != rear) {
    		int vertex = queue[++front];
    		printf("%d ", vertex);
  	 
    		for(int i = 0; i < n; i++) {
        			if(graph[vertex][i] == 1 && !visited[i]) {
            			visited[i] = 1;
            			queue[++rear] = i;
        			}
    		}
	}
	printf("\n");
}

void dfs(int graph[][MAX_VERTICES], int n, int start, int visited[])
{
	printf("%d ", start);
	visited[start] = 1;
   
	for(int i = 0; i < n; i++) {
 		  if(graph[start][i] == 1 && !visited[i]) {
        	dfs(graph, n, i, visited);
      }
	}
}
int main()
{
    int n, start;
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix for the graph:\n");
    for(int i = 0; i < n; i++)
    {
   	for(int j = 0; j < n; j++)
   	{
   	 scanf("%d", &graph[i][j]);
   	}
    }
    printf("Enter the starting node: ");
    scanf("%d", &start);

    bfs(graph, n, start);

    int visited[MAX_VERTICES] = {0};
    printf("DFS traversal: ");
    dfs(graph, n, start, visited);
    printf("\n");

    return 0;
}

