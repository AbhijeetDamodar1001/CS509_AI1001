#include "blocking.h"
#include <vector>
#include <algorithm>

void gemmBlocking(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B,
    vector<vector<int>>& C,
    int m,
    int k,
    int n,
    int blockSize)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            C[i][j] = 0;
        }
    }

    for(int ii = 0; ii < m; ii += blockSize)
    {
        for(int jj = 0; jj < n; jj += blockSize)
        {
            for(int kk = 0; kk < k; kk += blockSize)
            {
                for(int i = ii; i < min(ii + blockSize, m); i++)
                {
                    for(int j = jj; j < min(jj + blockSize, n); j++)
                    {
                        for(int x = kk; x < min(kk + blockSize, k); x++)
                        {
                            C[i][j] += A[i][x] * B[x][j];
                        }
                    }
                }
            }
        }
    }
}
