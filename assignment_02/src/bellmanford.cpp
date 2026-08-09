#include "bellmanford.h"

#include <vector>    // Input file driver.cpp mein dali hai
#include <climits>

using namespace std;

vector<int> bellmanFord(const csrgraph &graph,
                        int vertices,
                        int source,
                        bool &negativeCycle)
{
    // Distance array
    vector<int> distance(vertices, INT_MAX);

    // Source vertex distance
    distance[source] = 0;

    // Initially assume no negative cycle
    negativeCycle = false;

    // Relax all edges (V-1) times
    for(int i = 0; i < vertices - 1; i++)
    {
        bool updated = false;

        for(int u = 0; u < vertices; u++)
        {
            for(int j = graph.rowPtr[u]; j < graph.rowPtr[u + 1]; j++)
            {
                int v = graph.colIdx[j];
                int weight = graph.values[j];

                if(distance[u] != INT_MAX &&
                   distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                    updated = true;
                }
            }
        }

        // Stop early if no update happened
        if(!updated)
        {
            break;
        }
    }

    // Check for negative weight cycle
    for(int u = 0; u < vertices; u++)
    {
        for(int j = graph.rowPtr[u]; j < graph.rowPtr[u + 1]; j++)
        {
            int v = graph.colIdx[j];
            int weight = graph.values[j];

            if(distance[u] != INT_MAX &&
               distance[u] + weight < distance[v])
            {
                negativeCycle = true;
                return distance;
            }
        }
    }

    return distance;
}
