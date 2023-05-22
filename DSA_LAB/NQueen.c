#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int a[30], count = 0;

int place(int k)
{
    int i;
    for (i = 1; i < k; i++)
    {
        if ((a[i] == a[k]) || ((abs(a[i] - a[k]) == abs(i - k))))
            return 0;
    }
    return 1;
}

void print_solution(int n)
{
    count++;
    printf("\n\nSolution #%d:\n", count);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == j)
                printf("%d ", j);
        }
    }
}

void Nqueen(int n)
{
    int k = 1;
    a[k] = 0;
    while (k != 0)
    {
        a[k] = a[k] + 1;
        while ((a[k] <= n) && !place(k))
        {
            a[k]++;
        }
        if (a[k] <= n)
        {
            if (k == n)
            {
                print_solution(n);
            }
            else
            {
                k++;
                a[k] = 0;
            }
        }
        else
        {
            k--;
        }
    }
}

void main()
{
    int i, n;
    printf("Enter the number of Queens\n");
    scanf("%d", &n);
    Nqueen(n);
    printf("\nTotal solutions=%d\n", count);
}
