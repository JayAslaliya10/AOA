// #include <bits/stdc++.h>

// using namespace std;

// struct Edge
// {
//     int src, dest, wt;
// };

// struct Graph
// {
//     int V, E;
//     struct Edge *edge;
// };

// struct Graph *createGraph(int V, int E)
// {
//     struct Graph *graph = new Graph;
//     graph->V = V;
//     graph->E = E;
//     graph->edge = new Edge[E];
//     return graph;
// }

// void printArr(int dist[], int V)
// {
//     cout << "Vertex   Distance from sources" << endl;
//     for (int i = 0; i < V; i++)
//         cout << i << "\t\t" << dist[i] << endl;
// }

// void BellmanFord(struct Graph *graph, int src)
// {
//     int V = graph->V, E = graph->E;
//     int dist[V];

//     for (int i = 0; i < V; i++)
//         dist[i] = INT32_MAX;
//     dist[src] = 0;

//     for (int i = 0; i < V; i++)
//     {
//         for (int j = 0; j < E; j++)
//         {
//             int u = graph->edge[j].src;
//             int v = graph->edge[j].dest;
//             int wt = graph->edge[j].wt;

//             if (dist[u] != INT32_MAX && (dist[u] + wt < dist[v]))
//                 dist[v] = dist[u] + wt;
//         }
//     }

//     for (int i = 0; i < E; i++)
//     {
//         int u = graph->edge[i].src;
//         int v = graph->edge[i].dest;
//         int wt = graph->edge[i].wt;

//         if (dist[u] != INT32_MAX && dist[u] + wt < dist[v])
//         {
//             cout << "Graph contains negative weight cycle" << endl;
//             return;
//         }
//     }

//     printArr(dist, V);
//     return;
// }

// int main()
// {
//     int V = 5, E = 8;

//     struct Graph *graph = createGraph(V, E);

//     // add edge 0-1 (or A-B in above figure)
//     graph->edge[0].src = 0;
//     graph->edge[0].dest = 1;
//     graph->edge[0].wt = -1;

//     // add edge 0-2 (or A-C in above figure)
//     graph->edge[1].src = 0;
//     graph->edge[1].dest = 2;
//     graph->edge[1].wt = 4;

//     // add edge 1-2 (or B-C in above figure)
//     graph->edge[2].src = 1;
//     graph->edge[2].dest = 2;
//     graph->edge[2].wt = 3;

//     // add edge 1-3 (or B-D in above figure)
//     graph->edge[3].src = 1;
//     graph->edge[3].dest = 3;
//     graph->edge[3].wt = 2;

//     // add edge 1-4 (or B-E in above figure)
//     graph->edge[4].src = 1;
//     graph->edge[4].dest = 4;
//     graph->edge[4].wt = 2;

//     // add edge 3-2 (or D-C in above figure)
//     graph->edge[5].src = 3;
//     graph->edge[5].dest = 2;
//     graph->edge[5].wt = 5;

//     // add edge 3-1 (or D-B in above figure)
//     graph->edge[6].src = 3;
//     graph->edge[6].dest = 1;
//     graph->edge[6].wt = 1;

//     // add edge 4-3 (or E-D in above figure)
//     graph->edge[7].src = 4;
//     graph->edge[7].dest = 3;
//     graph->edge[7].wt = -3;

//     BellmanFord(graph, 0);

//     return 0;
// }

#include <bits/stdc++.h>
#define inf INT32_MAX;
int G[10][10], d[10], p[10], edge[10][3];

using namespace std;

void readGraph(int V)
{
    cout << "Enter the graph matrix : " << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cin >> G[i][j];
    }
}

void displayGraph(int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << G[i][j] << "\t";
        cout << endl;
    }
}

void createTable(int V, int E)
{
    int k = 0;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (G[i][j] != 0)
            {
                edge[k][0] = i;
                edge[k][1] = j;
                edge[k][2] = G[i][j];
                k++;
            }
            else
                continue;
        }

        cout << "Edge Table : " << endl;
        for (int i = 0; i < E; i++)
            cout << edge[i][0] << " --> " << edge[i][1] << " : " << edge[i][2] << endl;
    }
}

void initialize(int V, int s)
{
    for (int i = 0; i < V; i++)
    {
        d[i] = inf;
        p[i] = -1;
    }
    d[s] = 0;
}

void Relax(int u, int v, int w)
{
    if (d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        p[v] = u;
    }
}

int negCycle(int E)
{
    for (int i = 0; i < E; i++)
    {
        if (edge[i][1] > edge[i][0] + edge[i][2])
            return 0;

        return 1;
    }
}

void printPath(int s, int v)
{
    if (v == s)
        cout << s;
    else if (p[v] == -1)
        cout << "No path exists";
    else
    {
        printPath(s, p[v]);
        cout << " --> " << v;
    }
}

int main()
{
    int V, E, s;
    cout << "Enter the number of vertices : ";
    cin >> V;
    cout << "Enter the number of Edges : ";
    cin >> E;

    readGraph(V);
    cout << "Graph is : " << endl;
    displayGraph(V);

    createTable(V, E);

    cout << "Enter the source vertex : ";
    cin >> s;
    initialize(V, s);

    cout << "\n shortest path estimate after initialization : " << endl;
    for (int i = 0; i < V; i++)
        cout << d[i] << "\t";

    cout << endl;
    cout << "\n predecessor after initialization : " << endl;
    for (int i = 0; i < V; i++)
        cout << p[i] << "\t";

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
            Relax(edge[j][0], edge[j][1], edge[j][2]);
    }

    int flag = negCycle(E);
    if (flag == 0)
    {
        cout << "Negative weight cycle exists" << endl;
        return;
    }
    else
        cout << "SSSP exists" << endl;

    cout << "Printing path : " << endl;
    for (int i = 0; i < V; i++)
    {
        if (i == s)
            continue;

        cout << "Path from " << s << " to " << i << " : ";
        printPath(s, i);
        cout << endl;
    }

    return 0;
}