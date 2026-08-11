#include "floydwarshall.h"

using namespace std;

void floydWarshall(
    vector<vector<int>>& distance,
    bool& negativeCycle
)
{
    int vertices = distance.size();

    negativeCycle = false;

  
    for (int k = 0; k < vertices; k++)
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (distance[i][k] != 1000000000 &&
                    distance[k][j] != 1000000000)
                {
                    if (distance[i][k] + distance[k][j] < distance[i][j])
                    {
                        distance[i][j] =
                            distance[i][k] + distance[k][j];
                    }
                }
            }
        }
    }

   
    for (int i = 0; i < vertices; i++)
    {
        if (distance[i][i] < 0)
        {
            negativeCycle = true;
            break;
        }
    }
}
