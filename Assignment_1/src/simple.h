#ifndef SIMPLE_H
#define SIMPLE_H

#include <vector>
using namespace std;

void gemmSimple(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B,
    vector<vector<int>>& C,
    int M,
    int K,
    int N
);

#endif
