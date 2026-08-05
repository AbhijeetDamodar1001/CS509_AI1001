#include "simple.h"

vector<vector<int>> simpleMultiply(
    const vector<vector<int>>& matrixA,
    const vector<vector<int>>& matrixB
)
{
    int rowsA = matrixA.size();
    int colsA = matrixA[0].size();
    int colsB = matrixB[0].size();

    
    vector<vector<int>> resultMatrix(rowsA, vector<int>(colsB, 0));

    
    for (int i = 0; i < rowsA; i++)
{
    for (int k = 0; k < colsA; k++)
    {
        for (int j = 0; j < colsB; j++)
        {
            resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
        }
    }
}

    return resultMatrix;
}
