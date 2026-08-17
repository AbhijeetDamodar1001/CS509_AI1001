#include "prim.h"
#include <queue>
#include <limits>
#include <functional>

int primMST(
    const csrgraph& graph,
    vector<MSTEdge>& mst
)
{
    int vertices = graph.rowPtr.size() - 1;

    if (vertices == 0)
        return 0;

    vector<int> used(vertices, 0);
    vector<int> best(vertices, numeric_limits<int>::max());
    vector<int> parent(vertices, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    best[0] = 0;
    pq.push({0, 0});

    int totalWeight = 0;

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (used[u])
            continue;

        used[u] = 1;

        if (parent[u] != -1)
        {
            mst.push_back({parent[u], u, weight});
            totalWeight += weight;
        }

        for (int i = graph.rowPtr[u]; i < graph.rowPtr[u + 1]; i++)
        {
            int v = graph.colIdx[i];
            int w = graph.values[i];

            if (!used[v] && w < best[v])
            {
                best[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }

    return totalWeight;
}
