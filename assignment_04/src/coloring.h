#ifndef COLORING_H
#define COLORING_H

#include <vector>
#include "csr.h"

using namespace std;

vector<int> greedyColoring(const csrgraph& graph, int& colorsUsed);
bool checkColoring(const csrgraph& graph, const vector<int>& color);

#endif
