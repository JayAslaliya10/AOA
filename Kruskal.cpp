#include <bits/stdc++.h>

using namespace std;

class DSU
{
    int *parent, *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph
{
    vector<vector<int>> EdgeList;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int x, int y, int w)
    {
        EdgeList.push_back({w, x, y});
    }

    void Kruskal()
    {
        sort(EdgeList.begin(), EdgeList.end());

        DSU dsu(V);

        int ans = 0;
        for (auto edge : EdgeList)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if (dsu.find(x) != dsu.find(y))
            {
                dsu.unite(x, y);
                ans += w;
                cout << x << " --- " << y << "  ==  " << w << endl;
            }
        }

        cout << "Cost of minimum spanning tree : " << ans << endl;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);

    g.Kruskal();

    return 0;
}