#include "blocking.h"
#include <algorithm>

vector<vector<int>> blockingMultiply(
    const vector<vector<int>>& matrixA,
    const vector<vector<int>>& matrixB,
    int blockSize
)
{
    int rowsA = matrixA.size();
    int colsA = matrixA[0].size();
    int colsB = matrixB[0].size();

    vector<vector<int>> resultMatrix(rowsA, vector<int>(colsB, 0));

    for (int ii = 0; ii < rowsA; ii += blockSize)
    {
        for (int kk = 0; kk < colsA; kk += blockSize)
        {
            for (int jj = 0; jj < colsB; jj += blockSize)
            {
                int rowLimit = min(ii + blockSize, rowsA);
                int colLimitA = min(kk + blockSize, colsA);
                int colLimitB = min(jj + blockSize, colsB);

                for (int i = ii; i < rowLimit; i++)
                {
                    for (int k = kk; k < colLimitA; k++)
                    {
                        for (int j = jj; j < colLimitB; j++)
                        {
                            resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
                        }
                    }
                }
            }
        }
    }

    return resultMatrix;
}
