// PROGRAM TO IMPLEMENT ADDITION AND DELETION OF NODES
// AND EDGES IN A GRAPH USING ADJACENCY MATRIX
// CODED AND COMPILED IN TURBO C
#include <conio.h>
#include <stdio.h>
#include <process.h>
#define max 20
int adj[max][max];
int n;
void create_graph()
{
	int i, max_edges, origin, destin;
	printf("\nEnter number of nodes : ");
	scanf("%d", &n);
	max_edges = n * (n–1); /* Taking directed graph */
	for (i = 1; i <= max_edges; i++)
	{
		printf("\nEnter edge %d(0 0) to quit:", i);
		scanf("%d%d", &origin, &destin);
		if ((origin == 0) && (destin == 0))
			break;
		if (origin > n || destin > n || origin <= 0 || destin <= 0)
		{
			printf("\nInvalid edge !\n");
			i--;
		}
		else
			adj[origin][destin] = 1;
	} /*End of for*/
} /*End of create_graph()*/
void display()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			printf("%4d ", adj[i][j]);
		printf("\n");
	}
} /*End of display()*/
void insert_node()
{
	int i;
	n++; /*Increase number of nodes in the graph*/
	printf("\nThe inserted node is % d \n", n);
	for (i = 1; i <= n; i++)
	{
		adj[i][n] = 0;
		adj[n][i] = 0;
	}
} /*End of insert_node()*/
void delete_node(char u)
{
	int i, j;
	if (n == 0)
	{
		printf("\nGraph is empty\n");
		return;
	}
	if (u > n)
	{
		printf("\nThis node is not present in the graph\n");
		return;
	}
	for (i = u; i <= n - 1; i++)
		for (j = 1; j <= n; j++)
		{
			adj[j][i] = adj[j][i + 1]; /* Shift columns left */
			adj[i][j] = adj[i + 1][j]; /* Shift rows up */
		}
	n--; /*Decrease the number of nodes in the graph */
} /*End of delete_node*/
void insert_edge(char u, char v)
{
	if (u > n)
	{
		printf("\nSource node does not exist\n");
		return;
	}
	if (v > n)
	{
		printf("\nDestination node does not exist\n");
		return;
	}
	adj[u][v] = 1;
} /*End of insert_edge()*/
void del_edge(char u, char v)
{
	if (u > n || v > n || adj[u][v] == 0)
	{
		printf("\nThis edge does not exist\n");
		return;
	}
	adj[u][v] = 0;
} /*End of del_edge()*/
void main()
{
	int choice;
	int node, origin, destin;
	create_graph();
	while (1)
	{
		clrscr();
		printf("\n1.Insert a node\n");
		printf("2.Insert an edge\n");
		printf("3.Delete a node\n");
		printf("4.Delete an edge\n");
		printf("5.Dispaly\n");
		printf("6.Exit\n");
		printf ("\nEnter your choice:");
		scanf("% d", &choice);
		switch (choice)
		{
			case 1:
				insert_node();
				break;
			case 2:
				printf("\nEnter an edge to be inserted
					   :");
				fflush(stdin);
				scanf("% d % d", &origin, &destin);
				insert_edge(origin, destin);
				break;
			case 3:
				printf("\nEnter a node to be deleted
					   :");
				fflush(stdin);
				scanf("% d", &node);
				delete_node(node);
				break;
			case 4:
				printf("\nEnter an edge to be deleted
					   :");
				fflush(stdin);
				scanf("% d % d", &origin, &destin);
				del_edge(origin, destin);
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
			default:
				printf("\nWrong choice\n");
				break;
		} /*End of switch*/
	}/*End of while*/
} /*End of main()*/