#ifndef BLOCKING_H
#define BLOCKING_H

#include <vector>
using namespace std;

void gemmBlocking(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B,
    vector<vector<int>>& C,
    int m,
    int k,
    int n,
    int blockSize
);

#endif
