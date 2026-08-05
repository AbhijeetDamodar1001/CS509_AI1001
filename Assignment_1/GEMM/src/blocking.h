#ifndef BLOCKING_H
#define BLOCKING_H

#include <vector>

using namespace std;


vector<vector<int>> blockingMultiply(
    const vector<vector<int>>& matrixA,
    const vector<vector<int>>& matrixB,
    int blockSize
);

#endif
