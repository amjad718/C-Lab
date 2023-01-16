#include<stdio.h>
#define INFINITY 9999
void dijkstra(int G[10][10], int n, int start);
int main()
{
    int G[10][10], i, j, n, u;
    printf("Enter no. of vertices:");
    scanf("%d", & n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("enter the distance between %d and %d :", i, j);
            scanf("%d", & G[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the starting node:");
    scanf("%d", & u);
    dijkstra(G, n, u);
    return 0;
}
void dijkstra(int G[10][10], int n, int start)
{
    int cost[10][10], distance[10], pred[10];
    int visited[10], count, min, nextnode, i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = G[i][j];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
    distance[start] = 0;
    visited[start] = 1;
    count = 1;
    while (count < n)
    {
        min = INFINITY;
        for (i = 0; i < n; i++)
        {
            if (distance[i] < min && !visited[i])
            {
                min = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (min + cost[nextnode][i] < distance[i])
                {
                    distance[i] = min + cost[nextnode][i];
                    pred[i] = nextnode;
                }
                count++;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (i != start)
        {
            printf("\nDistance of node%d=%d", i, distance[i]);
            printf("\nPath=%d", i);
            j = i;
            do
            {
                j = pred[j];
                printf("<-%d", j);
            }
            while (j != start);
        }
    }
}
