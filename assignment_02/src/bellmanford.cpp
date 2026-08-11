#include "bellmanford.h"

#include <vector>    
#include <climits>

using namespace std;

vector<int> bellmanFord(const csrgraph &graph,
                        int vertices,
                        int source,
                        bool &negativeCycle)
{
    
    vector<int> distance(vertices, INT_MAX);

    distance[source] = 0;

    
    negativeCycle = false;

    
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

        
        if(!updated)
        {
            break;
        }
    }

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
