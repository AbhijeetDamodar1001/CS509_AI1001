#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <climits>

#include "../src/bellmanford.h"
#include "../src/floydwarshall.h"
#include "../../assignment_01/CSR/src/csr.h"

using namespace std;
using namespace chrono;

const string BF_FILE = "tests/bf_50000.txt";
const string FW_FILE = "tests/fw_10.txt";

const int INF = 1000000000;

int main()
{
    int choice;

    cout << "1. Bellman-Ford" << endl;
    cout << "2. Floyd-Warshall" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        ifstream inputFile(BF_FILE);

        if (!inputFile)
        {
            cout << "Could not open Bellman-Ford input file." << endl;
            return 1;
        }

        int vertices, edges;
        inputFile >> vertices >> edges;

        vector<vector<pair<int, int>>> adjacencyList(vertices);

        for (int i = 0; i < vertices; i++)
        {
            int vertex, degree;
            inputFile >> vertex >> degree;

            for (int j = 0; j < degree; j++)
            {
                int neighbour, weight;
                inputFile >> neighbour >> weight;

                adjacencyList[vertex].push_back({neighbour, weight});
            }
        }

        string word;
        int source;

        inputFile >> word >> source;
        inputFile.close();

       
        csrgraph graph = convert_to_csr(adjacencyList);

        bool negativeCycle = false;

        auto start = high_resolution_clock::now();

        vector<int> distance =
            bellmanFord(graph, vertices, source, negativeCycle);

        auto stop = high_resolution_clock::now();

        auto timeTaken =
            duration_cast<microseconds>(stop - start);

        cout << "\nAlgorithm: Bellman-Ford" << endl;
        cout << "Source: " << source << endl;

        if (negativeCycle)
        {
            cout << "Negative cycle: true" << endl;
        }
        else
        {
            cout << "\nVertex Distance" << endl;

            for (int i = 0; i < vertices; i++)
            {
                cout << i << " ";

                if (distance[i] == INT_MAX)
                {
                    cout << "INF";
                }
                else
                {
                    cout << distance[i];
                }

                cout << endl;
            }

            cout << "Negative cycle: none" << endl;
        }

        cout << "Execution time: "
             << timeTaken.count()
             << " microseconds" << endl;
    }
    else if (choice == 2)
    {
        ifstream inputFile(FW_FILE);

        if (!inputFile)
        {
            cout << "Could not open Floyd-Warshall input file." << endl;
            return 1;
        }

        int vertices;
        inputFile >> vertices;

        vector<vector<int>> distance(
            vertices,
            vector<int>(vertices)
        );

        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                string value;
                inputFile >> value;

                if (value == "INF")
                {
                    distance[i][j] = INF;
                }
                else
                {
                    distance[i][j] = stoi(value);
                }
            }
        }

        inputFile.close();

        bool negativeCycle = false;

        auto start = high_resolution_clock::now();

        floydWarshall(distance, negativeCycle);

        auto stop = high_resolution_clock::now();

        auto timeTaken =
            duration_cast<microseconds>(stop - start);

        cout << "\nAlgorithm: Floyd-Warshall" << endl;

        if (negativeCycle)
        {
            cout << "Negative cycle: true" << endl;
        }
        else
        {
            cout << "\nDistance matrix:" << endl;

            for (int i = 0; i < vertices; i++)
            {
                for (int j = 0; j < vertices; j++)
                {
                    if (distance[i][j] == INF)
                    {
                        cout << "INF ";
                    }
                    else
                    {
                        cout << distance[i][j] << " ";
                    }
                }

                cout << endl;
            }

            cout << "Negative cycle: none" << endl;
        }

        cout << "Execution time: "
             << timeTaken.count()
             << " microseconds" << endl;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
