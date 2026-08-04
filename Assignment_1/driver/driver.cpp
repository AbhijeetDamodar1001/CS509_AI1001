#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cstdlib>

#include "../src/simple.h"
#include "../src/blocking.h"

using namespace std;

void readMatrices(
    const string& fileName,
    vector<vector<int>>& matrixA,
    vector<vector<int>>& matrixB)
{
    ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        cout << "Error: Unable to open input file." << endl;
        exit(EXIT_FAILURE);
    }

    int rowsA, colsA, colsB;

    if (!(inputFile >> rowsA >> colsA >> colsB))
    {
        cout << "Error: Invalid matrix dimensions." << endl;
        exit(EXIT_FAILURE);
    }

    matrixA.resize(rowsA, vector<int>(colsA));
    matrixB.resize(colsA, vector<int>(colsB));

    
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            if (!(inputFile >> matrixA[i][j]))
            {
                cout << "Error: Invalid data in Matrix A." << endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    
    for (int i = 0; i < colsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            if (!(inputFile >> matrixB[i][j]))
            {
                cout << "Error: Invalid data in Matrix B." << endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    inputFile.close();
}


void printMatrix(const vector<vector<int>>& matrix, const string& title)
{
    cout << "\n" << title << endl;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    const int BLOCK_SIZE = 32;

    
    string fileName = "tests/test_01.txt";

    vector<vector<int>> matrixA;
    vector<vector<int>> matrixB;

    readMatrices(fileName, matrixA, matrixB);

    

    auto startSimple = chrono::high_resolution_clock::now();

    vector<vector<int>> simpleResult =
        simpleMultiply(matrixA, matrixB);

    auto endSimple = chrono::high_resolution_clock::now();

    auto simpleTime =
        chrono::duration<double, milli>(endSimple - startSimple);

    printMatrix(simpleResult, "Simple GEMM Result");

    cout << "Execution Time : "
         << simpleTime.count()
         << " ms" << endl;

    
    auto startBlock = chrono::high_resolution_clock::now();

    vector<vector<int>> blockingResult =
        blockingMultiply(matrixA, matrixB, BLOCK_SIZE);

    auto endBlock = chrono::high_resolution_clock::now();

    auto blockingTime =
        chrono::duration<double, milli>(endBlock - startBlock);

    printMatrix(blockingResult, "Blocking GEMM Result");

    cout << "Execution Time : "
         << blockingTime.count()
         << " ms" << endl;

    return 0;
}
