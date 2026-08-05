#include <iostream>
#include <fstream>
#include <vector>

#include "../src/csr.h"

using namespace std;

int main()
{
    string fileName = "tests/graph_1.txt";

    ifstream inputFile(fileName);

    if (!inputFile)
    {
        cout << "File could not be opened." << endl;
        return 0;
    }

    int vertices, edges;
    inputFile >> vertices >> edges;

    vector<vector<pair<int, int>>> graph(vertices);

    for (int i = 0; i < vertices; i++)
    {
        int source, degree;
        inputFile >> source >> degree;

        for (int j = 0; j < degree; j++)
        {
            int destination, weight;
            inputFile >> destination >> weight;

            graph[source].push_back({destination, weight});
        }
    }

    inputFile.close();

    csrgraph csr = convert_to_csr(graph);

    cout << "\nRow Pointer\n";

    for (int i = 0; i < csr.rowPtr.size(); i++)
    {
        cout << csr.rowPtr[i] << " ";
    }

    cout << "\n\nColumn Index\n";

    for (int i = 0; i < csr.colIdx.size(); i++)
    {
        cout << csr.colIdx[i] << " ";
    }

    cout << "\n\nValues\n";

    for (int i = 0; i < csr.values.size(); i++)
    {
        cout << csr.values[i] << " ";
    }

    cout << endl;

    return 0;
}
