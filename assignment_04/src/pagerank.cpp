#include "pagerank.h"
#include <cmath>

vector<double> pageRank(const csrgraph& graph, double damping,
                        double tolerance, int maxIterations,
                        int& iterations, bool& converged)
{
    int n = graph.rowPtr.size() - 1;
    vector<double> rank(n, 1.0 / n);
    vector<double> next(n);

    iterations = 0;
    converged = false;

    for (int step = 0; step < maxIterations; step++)
    {
        double dangling = 0.0;

        for (int u = 0; u < n; u++)
        {
            if (graph.rowPtr[u] == graph.rowPtr[u + 1])
                dangling += rank[u];
        }

        double base = (1.0 - damping) / n;
        double extra = damping * dangling / n;

        for (int v = 0; v < n; v++)
            next[v] = base + extra;

        for (int u = 0; u < n; u++)
        {
            int degree = graph.rowPtr[u + 1] - graph.rowPtr[u];
            if (degree == 0)
                continue;

            double part = damping * rank[u] / degree;

            for (int i = graph.rowPtr[u]; i < graph.rowPtr[u + 1]; i++)
            {
                int v = graph.colIdx[i];
                next[v] += part;
            }
        }

        double change = 0.0;
        for (int i = 0; i < n; i++)
            change += fabs(next[i] - rank[i]);

        rank = next;
        iterations++;

        if (change <= tolerance)
        {
            converged = true;
            break;
        }
    }

    return rank;
}
