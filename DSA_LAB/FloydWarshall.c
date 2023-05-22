#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void FloydWarshall(int **d, int n)
{
    int s = n;
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (d[i][j] > (d[i][k] + d[k][j]))
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter number of nodes \n");
    scanf("%d", &n);
    int **g = (int **)malloc(n * sizeof(int *));
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            g[i] = (int *)malloc(n * sizeof(int));
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                g[i][j] = 0;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter weights for row %d \n", i + 1);
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                printf("Press 1 for joint node, 0 for disjoint node \n");
                int ch;
                scanf("%d", &ch);
                if (ch == 1)
                {
                    printf("Enter weight \n");
                    scanf("%d", &g[i][j]);
                }
                if (ch == 0)
                {
                    g[i][j] = 9999;
                }
            }
            else
            {
                printf("Both the indices are same \n");
            }
        }
    }
    printf("The Original Matrix \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d \t", g[i][j]);
        }
        printf("\n");
    }
    FloydWarshall(g, n);
    printf("Shortest path matrix is: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d \t", g[i][j]);
        }
        printf("\n");
    }
    return 0;
}





