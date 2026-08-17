#ifndef PRIM_H
#define PRIM_H

#include <vector>
#include "../../assignment_01/CSR/src/csr.h"
#include "kruskal.h"

using namespace std;

int primMST(
    const csrgraph& graph,
    vector<MSTEdge>& mst
);

#endif
