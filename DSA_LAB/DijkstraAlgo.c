#include <stdio.h>
#include <stdbool.h>

#define MAX 1000
#define INF 99999

int n = 5; // number of vertices
int start = 0; // starting vertex

char vertexName[5] = {'s', 't', 'x', 'y', 'z'};

// adjacency matrix of the given graph
int graph[5][5] = {
            /* S  T  X  Y  Z */
    /* S */    {0, 10, 0, 5, 0},
    /* T */    {0, 0, 1, 2, 0},
    /* X */    {0, 0, 0, 0, 4},
    /* Y */    {0, 3, 9, 0, 2},
    /* Z */    {7, 0, 6, 0, 0}
};

int distance[MAX];
bool visitedNode[MAX];
int parentNode[MAX];



int minDistance() {
    int minIndex = -1, minDist = INF;
    for (int i = 0; i < n; i++) {
        if (!visitedNode[i] && distance[i] < minDist) {
            minDist = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstraAlgorithm() {
    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visitedNode[i] = false;
        parentNode[i] = -1;
    }

    distance[start] = 0;

    for (int i = 0; i < n-1; i++) {
        int u = minDistance(n);
        visitedNode[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visitedNode[v] && graph[u][v] && distance[u] != INF && distance[u]+graph[u][v] < distance[v]) {
                distance[v] = distance[u]+graph[u][v];
                parentNode[v] = u;
            }
        }
    }
}

void display() {
    char vertex;
    char parent;
    for (int i = 0; i < n; i++) {    
        printf("d[%c]=%d, p[%c]=", vertexName[i], distance[i], vertexName[i]);
        if (parentNode[i] == -1) {
            printf("NULL\n");
        } else {
            printf("%c\n", vertexName[parentNode[i]]);
        }
    }
}

int main() {

    dijkstraAlgorithm();
    display();

    return 0;
}
