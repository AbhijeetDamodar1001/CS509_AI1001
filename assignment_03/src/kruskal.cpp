#include "kruskal.h"
#include <algorithm>

int findParent(vector<int>& parent, int x)
{
    if (parent[x] == x)
        return x;

    parent[x] = findParent(parent, parent[x]);
    return parent[x];
}

bool compareEdges(const MSTEdge& a, const MSTEdge& b)
{
    return a.weight < b.weight;
}

int kruskalMST(
    const csrgraph& graph,
    vector<MSTEdge>& mst
)
{
    int vertices = graph.rowPtr.size() - 1;
    vector<MSTEdge> allEdges;

    for (int u = 0; u < vertices; u++)
    {
        for (int i = graph.rowPtr[u]; i < graph.rowPtr[u + 1]; i++)
        {
            int v = graph.colIdx[i];
            int w = graph.values[i];

            if (u < v)
                allEdges.push_back({u, v, w});
        }
    }

    sort(allEdges.begin(), allEdges.end(), compareEdges);

    vector<int> parent(vertices);
    vector<int> rank(vertices, 0);

    for (int i = 0; i < vertices; i++)
        parent[i] = i;

    int totalWeight = 0;

    for (int i = 0; i < allEdges.size(); i++)
    {
        int a = findParent(parent, allEdges[i].from);
        int b = findParent(parent, allEdges[i].to);

        if (a != b)
        {
            mst.push_back(allEdges[i]);
            totalWeight += allEdges[i].weight;

            if (rank[a] < rank[b])
                parent[a] = b;
            else if (rank[a] > rank[b])
                parent[b] = a;
            else
            {
                parent[b] = a;
                rank[a]++;
            }

            if (mst.size() == vertices - 1)
                break;
        }
    }

    return totalWeight;
}
