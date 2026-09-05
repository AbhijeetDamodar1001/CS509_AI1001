#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <cmath>

#include "../src/coloring.h"
#include "../src/pagerank.h"

using namespace std;
using namespace chrono;

bool readGraph(const string& fileName, vector<vector<pair<int, int>>>& graph,
               bool directed, double& damping, double& tolerance,
               int& maxIterations)
{
    ifstream file(fileName);
    if (!file)
        return false;

    int vertices, edges;
    if (!(file >> vertices >> edges) || vertices <= 0 || edges < 0)
        return false;

    graph.assign(vertices, vector<pair<int, int>>());

    for (int i = 0; i < vertices; i++)
    {
        int u, degree;
        if (!(file >> u >> degree) || u < 0 || u >= vertices || degree < 0)
            return false;

        for (int j = 0; j < degree; j++)
        {
            int v;
            if (!(file >> v) || v < 0 || v >= vertices)
                return false;

            if (!directed && u == v)
                return false;

            graph[u].push_back({v, 1});
        }
    }

    if (directed)
    {
        string word;
        if (!(file >> word >> damping))
            return false;
        if (word != "DAMPING" || damping <= 0.0 || damping >= 1.0)
            return false;

        if (!(file >> word >> tolerance) || word != "TOLERANCE" || tolerance <= 0.0)
            return false;

        if (!(file >> word >> maxIterations) || word != "MAX_ITERATIONS" || maxIterations <= 0)
            return false;
    }

    return true;
}

csrgraph makeCSR(const vector<vector<pair<int, int>>>& graph)
{
    return convert_to_csr(graph);
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Usage: assignment4.exe color/pagerank testfile" << endl;
        return 1;
    }

    string choice = argv[1];
    string fileName = argv[2];

    vector<vector<pair<int, int>>> list;
    double damping = 0.85;
    double tolerance = 0.0001;
    int maxIterations = 100;

    bool directed = (choice == "pagerank");

    if (choice != "color" && choice != "pagerank")
    {
        cout << "Invalid algorithm." << endl;
        return 1;
    }

    if (!readGraph(fileName, list, directed, damping, tolerance, maxIterations))
    {
        cout << "Could not read input file." << endl;
        return 1;
    }

    csrgraph graph = makeCSR(list);
    int vertices = graph.rowPtr.size() - 1;

    if (choice == "color")
    {
        int colorsUsed = 0;
        auto start = high_resolution_clock::now();
        vector<int> color = greedyColoring(graph, colorsUsed);
        auto stop = high_resolution_clock::now();

        bool valid = checkColoring(graph, color);
        double time = duration<double, milli>(stop - start).count();

        cout << "Algorithm: Greedy Vertex Coloring" << endl;
        cout << "Vertex colors:" << endl;
        for (int i = 0; i < vertices; i++)
            cout << i << " " << color[i] << endl;

        cout << "Colors used: " << colorsUsed << endl;
        cout << "Valid: " << (valid ? "true" : "false") << endl;
        cout << "Execution time: " << time << " ms" << endl;
    }
    else
    {
        int iterations;
        bool converged;

        auto start = high_resolution_clock::now();
        vector<double> rank = pageRank(graph, damping, tolerance,
                                       maxIterations, iterations, converged);
        auto stop = high_resolution_clock::now();

        double time = duration<double, milli>(stop - start).count();
        double sum = 0.0;
        for (double x : rank)
            sum += x;

        cout << "Algorithm: PageRank" << endl;
        cout << "Damping: " << damping << endl;
        cout << "Vertex ranks:" << endl;
        for (int i = 0; i < vertices; i++)
            cout << i << " " << rank[i] << endl;

        cout << "Sum of ranks: " << sum << endl;
        cout << "Iterations: " << iterations << endl;
        cout << "Converged: " << (converged ? "true" : "false") << endl;
        cout << "Execution time: " << time << " ms" << endl;
    }

    return 0;
}
