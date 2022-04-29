// #include <bits/stdc++.h>
// using namespace std;

// #define V 5

// int minKey(int key[], bool mstSet[])
// {
//     int min = INT_MAX, min_index;

//     for (int v = 0; v < V; v++)
//         if (mstSet[v] == false && key[v] < min)
//             min = key[v], min_index = v;

//     return min_index;
// }

// void printMST(int parent[], int graph[V][V])
// {
//     cout << endl;
//     cout << " Edge \t  Weight\n";
//     for (int i = 1; i < V; i++)
//         cout << parent[i] << " - " << i << " \t    " << graph[i][parent[i]] << " \n";
// }

// void primMST(int graph[V][V])
// {
//     int parent[V];
//     int key[V];
//     bool mstSet[V];

//     for (int i = 0; i < V; i++)
//         key[i] = INT_MAX, mstSet[i] = false;

//     key[0] = 0;
//     parent[0] = -1;

//     for (int count = 0; count < V - 1; count++)
//     {
//         int u = minKey(key, mstSet);
//         mstSet[u] = true;

//         for (int v = 0; v < V; v++)
//             if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
//                 parent[v] = u, key[v] = graph[u][v];
//     }

//     printMST(parent, graph);
// }

// int main()
// {
//     int graph[V][V] = {{0, 2, 0, 6, 0},
//                        {2, 0, 3, 8, 5},
//                        {0, 3, 0, 0, 7},
//                        {6, 8, 0, 0, 9},
//                        {0, 5, 7, 9, 0}};

//     primMST(graph);

//     return 0;
// }

// ====================================================================================================================

// #include <bits/stdc++.h>

// using namespace std;

// #define inf INT32_MAX;
// int V = 0, E = 0, G[10][10], p[10], d[10], visited[10], start;

// void readGraph()
// {
//     cout << "Enter the adjacency matrix : " << endl;
//     for (int i = 0; i < V; i++)
//     {
//         for (int j = 0; j < V; j++)
//         {
//             cin >> G[i][j];
//             if (G[i][j] != 0)
//                 E++;
//         }
//     }
// }

// void displayGraph()
// {
//     cout << "Graph is : " << endl;
//     for (int i = 0; i < V; i++)
//     {
//         for (int j = 0; j < V; j++)
//         {
//             cout << G[i][j];
//         }
//         cout << endl;
//     }
// }

// void initialize()
// {
//     for (int i = 0; i < V; i++)
//     {
//         visited[i] = 0;
//         d[i] = inf;
//         p[i] = -1;
//     }
// }

// void Prims()
// {
//     int curr, totalvis, mincost;

//     cout << "Enter the starting vertex: ";
//     cin >> curr;

//     d[curr] = 0;
//     visited[curr] = 0;
//     totalvis = 1;

//     while (totalvis != V)
//     {
//         for (int i = 0; i < V; i++)
//         {
//             if (G[curr][i] != 0)
//             {
//                 if (visited[i] == 0)
//                 {
//                     d[i] = G[curr][i];
//                     p[i] = curr;
//                 }
//             }
//         }

//         mincost = INT32_MAX;
//         for (int i = 0; i < V; i++)
//         {
//             if (visited[i] == 0)
//             {
//                 if (d[i] < mincost)
//                 {
//                     mincost = d[i];
//                     curr = i;
//                 }
//             }
//         }

//         cout << endl
//              << "Edge (" << p[curr] << "," << curr << ")";
//         visited[curr] = 1;
//         totalvis++;

//         cout << "Edges are :" << endl;
//         for (int i = 0; i < V; i++)
//         {
//             mincost += d[i];
//             if (p[i] != 1)
//                 printf("\n Edge (%d,%d) : %d ", p[i], i, G[p[i]][i]);
//         }
//         cout << "\nTotal cost : " << mincost << endl;
//     }
// }

// void printPath(int s, int v)
// {
//     if (v == s)
//         printf(" %d ", s);
//     else if (v == start)
//     {
//         printf(" %d ", start);
//     }
//     else
//     {
//         printPath(s, p[v]);
//         printf("-->");
//         printf(" %d ", v);
//     }
// }

// int main()
// {
//     cout << "Enter the number of vertices : ";
//     cin >> V;

//     readGraph();

//     displayGraph();

//     cout << "No of vertex : " << V << "\tNo of eges : " << E << endl;

//     initialize();

//     Prims();

//     printf("\nPrinting Path\n");
//     for (int i = 0; i < V; i++)
//     {
//         if (i == start)
//             continue;
//         printf("path from %d to %d is ", start, i);
//         printPath(start, i);
//         printf("\n");
//     }

//     return 0;
// }

// =======================================================================================================

#include "stdio.h"
#include "stdlib.h"
#define INF 9999
int V, E = 0;
int G[10][10];
int p[10], visited[10], d[10];
int startvertex;

void readGraph()
{
    printf("\nEnter adjacenc matrix \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &G[i][j]);
            if (G[i][j] != 0)
                E++;
        }
    }
}

void displaygraph()
{
    printf("\nGraph is... \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d\t", G[i][j]);
        }
        printf("\n");
    }
}

void initialize()
{
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
        d[i] = INF;
        p[i] = -1;
    }
}

void print1Darray(char *str, int a[])
{
    printf("\n%s [] : ", str);

    for (int i = 0; i < V; i++)
    {
        printf("\t%d", a[i]);
    }
}

void print_vis_d_p()
{
    print1Darray("visited", visited);
    print1Darray("d array", d);
    print1Darray("p array", p);
}

void prims()
{
    int curr, totalvis, mincost, i;
    printf("\n\nEnter starting vertex : ");
    scanf("%d", &curr);
    startvertex = curr;
    // curr = 0;
    d[curr] = 0;
    visited[curr] = 1;
    totalvis = 1;
    printf("\n order in which edges are selected in MST: \n");
    while (totalvis != V)
    {
        for (int i = 0; i < V; i++)
        {
            if (G[curr][i] != 0)
            {
                if (visited[i] == 0)
                {
                    if (d[i] > G[curr][i])
                    {
                        d[i] = G[curr][i];
                        p[i] = curr;
                    }
                }
            }
        } // end of for

        mincost = 8999;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                if (d[i] < mincost)
                {

                    mincost = d[i];
                    curr = i;
                }
            }
        }
        printf("\nEdge (%d,%d)", p[curr], curr);
        visited[curr] = 1;
        totalvis++;
    }

    printf("\n\nFinal Values are ....");
    print_vis_d_p();

    mincost = 0;
    printf("\n\n Edges in minimum spanning tree are :\n ");
    for (int i = 0; i < V; i++)
    {
        mincost += d[i];
        if (p[i] != -1)
            printf("\n Edge (%d,%d) : %d ", p[i], i, G[p[i]][i]);
    }
    printf("\n\nTotal Cost : %d \n", mincost);
}

void printpath(int s, int v)
{
    if (v == s)
        printf(" %d ", s);
    else if (v == startvertex)
    {
        printf(" %d ", startvertex);
    }
    else
    {
        printpath(s, p[v]);
        printf("-->");
        printf(" %d ", v);
    }
}

void main()
{
    printf("\n Enter number of vertices\n");
    scanf("%d", &V);

    readGraph();

    displaygraph();

    printf("No.of vertex : %d\nNo.of Edges : %d\n", V, E);

    initialize();

    printf("\nAfter initialization....");

    print_vis_d_p();
    
    prims();


    printf("\nPrinting Path\n");
    for (int i = 0; i < V; i++)
    {
        if (i == startvertex)
            continue;
        printf("path from %d to %d is ", startvertex, i);
        printpath(startvertex, i);
        printf("\n");
    }
}