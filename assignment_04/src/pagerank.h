#ifndef PAGERANK_H
#define PAGERANK_H

#include <vector>
#include "csr.h"

using namespace std;

vector<double> pageRank(const csrgraph& graph, double damping,
                        double tolerance, int maxIterations,
                        int& iterations, bool& converged);

#endif
