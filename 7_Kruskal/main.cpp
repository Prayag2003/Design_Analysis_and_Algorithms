#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src;
    int dest;
    int wt;
};

class Graph
{
public:
    int vertices;
    int edges;
    Edge *edge;
};

struct subset
{
    int parent;
    int rank;
};

int find(subset *sub, int x)
{
    if (sub[x].parent != x)
    {
        sub[x].parent = find(sub, sub[x].parent);
    }
    return sub[x].parent;
}

void Union(subset *sub, int x, int y)
{
    int i = find(sub, x);
    int j = find(sub, y);
    if (sub[i].rank < sub[j].rank)
    {
        sub[i].parent = j;
    }
    else if (sub[i].rank > sub[i].rank)
    {
        sub[j].parent = i;
    }
    else
    {
        sub[j].parent = i;
        sub[i].rank++;
    }
}
bool cmp(Edge a, Edge b)
{
    return a.wt < b.wt;
}
int Kruskal(Graph g)
{
    int V = g.vertices;
    int E = g.edges;
    Edge result[V];
    int e = 0;
    int i = 0;
    subset *sub = new subset[V];
    for (int v = 0; v < V; v++)
    {
        sub[v].parent = v;
        sub[v].rank = 0;
    }
    while (e < V - 1 && i < E)
    {
        Edge next_edge = g.edge[i++];
        int x = find(sub, next_edge.src);
        int y = find(sub, next_edge.dest);
        if (x != y)
        {
            result[e++] = next_edge;
            Union(sub, x, y);
            cout << "Added edge: " << next_edge.src << next_edge.dest << " (weight " << next_edge.wt << ")" << endl;
        }
    }
    int cost = 0;
    for (int i = 0; i < e; i++)
    {
        cost += result[i].wt;
    }
    cout << "Minimum spanning tree cost: " << cost << endl;
    return cost;
}
int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    Graph g;
    g.vertices = V;
    g.edges = E;
    g.edge = new Edge[E];
    for (int i = 0; i < E; i++)
    {
        int s, d, wt;
        cout << "Enter source vertex: ";
        cin >> s;
        cout << "Enter destination vertex: ";
        cin >> d;
        cout << "Enter edge weight: ";
        cin >> wt;
        sort(g.edge, g.edge + E, cmp);
        g.edge[i].src = s;
        g.edge[i].dest = d;
        g.edge[i].wt = wt;
    }
    int cost = Kruskal(g);
    cout << "The cost of the Minimum Spanning Tree: " << cost << endl;
}