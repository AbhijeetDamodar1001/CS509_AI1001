#include "coloring.h"
#include <algorithm>

vector<int> greedyColoring(const csrgraph& graph, int& colorsUsed)
{
    int n = graph.rowPtr.size() - 1;
    vector<int> color(n, -1);
    vector<int> order(n);

    for (int i = 0; i < n; i++)
        order[i] = i;

    sort(order.begin(), order.end(), [&](int a, int b)
    {
        int da = graph.rowPtr[a + 1] - graph.rowPtr[a];
        int db = graph.rowPtr[b + 1] - graph.rowPtr[b];

        if (da != db)
            return da > db;
        return a < b;
    });

    for (int x = 0; x < n; x++)
    {
        int u = order[x];
        int start = graph.rowPtr[u];
        int end = graph.rowPtr[u + 1];

        int c = 0;
        bool used = true;

        while (used)
        {
            used = false;

            for (int i = start; i < end; i++)
            {
                int v = graph.colIdx[i];
                if (color[v] == c)
                {
                    used = true;
                    break;
                }
            }

            if (used)
                c++;
        }

        color[u] = c;
        if (c + 1 > colorsUsed)
            colorsUsed = c + 1;
    }

    return color;
}

bool checkColoring(const csrgraph& graph, const vector<int>& color)
{
    int n = graph.rowPtr.size() - 1;

    for (int u = 0; u < n; u++)
    {
        for (int i = graph.rowPtr[u]; i < graph.rowPtr[u + 1]; i++)
        {
            int v = graph.colIdx[i];
            if (color[u] == color[v])
                return false;
        }
    }

    return true;
}
