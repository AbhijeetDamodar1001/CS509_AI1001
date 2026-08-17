#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include "../../assignment_01/CSR/src/csr.h"

using namespace std;

struct MSTEdge
{
    int from;
    int to;
    int weight;
};

int kruskalMST(
    const csrgraph& graph,
    vector<MSTEdge>& mst
);

#endif
