#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H

#include <vector>

using namespace std;

void floydWarshall(
    vector<vector<int>>& distance,
    bool& negativeCycle
);

#endif
