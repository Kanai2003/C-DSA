#include<stdio.h>
#include<stdlib.h>

typedef struct Graph{
	int numOfVertices;
	int** adjMatrix;
}Graph;

//creat a graph of given number of vertices, vertices is starting from 0 to numOfVertices-1
Graph *	creatGraph(int numOfVertices){
	//allocate memory for the graph
	Graph *graph = malloc(sizeof(Graph));
	graph->numOfVertices = numOfVertices;

	//allocate memory for the adjancency matrix
	graph->adjMatrix = malloc(sizeof(int)*numOfVertices);
	for(int i = 0; i<graph->numOfVertices;i++){
		graph->adjMatrix[i] = malloc(numOfVertices*sizeof(int));
	}

	//initialize all values of adjancency matrix as 0
	for(int i  = 0; i<graph->numOfVertices;i++){
		for(int j =0; j<graph->numOfVertices;j++){
			graph->adjMatrix[i][j] = 0;
		}
	}

	return graph;
}

//function to add an edge between two vertices in the graph
void addEdge(Graph * graph, int src, int dest){
	graph->adjMatrix[src][dest] = 1;
	graph->adjMatrix[dest][src] = 1;
}

//fucntion to print the matrix form of the graph
void display(Graph * graph){
	for(int i = 0; i<graph->numOfVertices;i++){
		for(int j = 0;j<graph->numOfVertices;j++){
			printf("%d ",graph->adjMatrix[i][j]);
		}
		printf("\n");
	}
}

int main (){
	Graph *graph = creatGraph(5);
	printf("Initially : \n");
	display(graph);
	addEdge(graph,0,4);
	addEdge(graph,0,1);
	addEdge(graph,1,2);
	addEdge(graph,2,3);
	addEdge(graph,3,4);
	printf("After :\n");
	display(graph);


}