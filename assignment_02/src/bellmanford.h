#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include <vector>
#include "../../assignment_01/CSR/src/csr.h"

using namespace std;

vector<int> bellmanFord(
    const csrgraph& graph,
    int vertices,
    int source,
    bool& negativeCycle
);

#endif
