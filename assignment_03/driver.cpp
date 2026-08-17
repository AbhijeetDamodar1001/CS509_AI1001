#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <chrono>

#include "../../assignment_01/CSR/src/csr.h"
#include "../src/kruskal.h"
#include "../src/prim.h"

using namespace std;
using namespace chrono;

const string TEST_FILE = "tests/mst_10.txt";

int main()
{
    ifstream input(TEST_FILE);

    if (!input)
    {
        cout << "Could not open MST input file." << endl;
        return 1;
    }

    int vertices, edges;
    input >> vertices >> edges;

    vector<vector<pair<int, int>>> graph(vertices);

    for (int i = 0; i < vertices; i++)
    {
        int vertex, degree;
        input >> vertex >> degree;

        for (int j = 0; j < degree; j++)
        {
            int next, weight;
            input >> next >> weight;

            graph[vertex].push_back({next, weight});
        }
    }

    input.close();

    // Convert graph into CSR
    csrgraph csr = convert_to_csr(graph);

    // ---------------- Kruskal ----------------

    vector<MSTEdge> kruskalEdges;

    auto startKruskal = high_resolution_clock::now();

    int kruskalWeight =
        kruskalMST(csr, kruskalEdges);

    auto stopKruskal = high_resolution_clock::now();

    auto kruskalTime =
        duration_cast<microseconds>(
            stopKruskal - startKruskal
        );

    cout << "\nKruskal MST" << endl;

    for (int i = 0; i < kruskalEdges.size(); i++)
    {
        cout << kruskalEdges[i].from << " "
             << kruskalEdges[i].to << " "
             << kruskalEdges[i].weight << endl;
    }

    cout << "Total MST weight: "
         << kruskalWeight << endl;

    cout << "Execution time: "
         << kruskalTime.count() / 1000.0
         << " ms" << endl;


    // ---------------- Prim ----------------

    vector<MSTEdge> primEdges;

    auto startPrim = high_resolution_clock::now();

    int primWeight =
        primMST(csr, primEdges);

    auto stopPrim = high_resolution_clock::now();

    auto primTime =
        duration_cast<microseconds>(
            stopPrim - startPrim
        );

    cout << "\nPrim MST" << endl;

    for (int i = 0; i < primEdges.size(); i++)
    {
        cout << primEdges[i].from << " "
             << primEdges[i].to << " "
             << primEdges[i].weight << endl;
    }

    cout << "Total MST weight: "
         << primWeight << endl;

    cout << "Execution time: "
         << primTime.count() / 1000.0
         << " ms" << endl;


    // ---------------- Comparison ----------------

    cout << "\nComparison" << endl;

    if (kruskalWeight == primWeight)
    {
        cout << "Both algorithms produced the same MST weight."
             << endl;
    }
    else
    {
        cout << "MST weights are different." << endl;
    }

    return 0;
}
