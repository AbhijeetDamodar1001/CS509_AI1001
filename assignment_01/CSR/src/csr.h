#ifndef CSR_H
#define CSR_H

#include <vector>

using namespace std;

struct csrgraph
{
    vector<int> rowPtr;
    vector<int> colIdx;
    vector<int> values;
};

csrgraph convert_to_csr(
    const vector<vector<pair<int, int>>>& adjacencyList
);

#endif
