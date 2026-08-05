#include "csr.h"

csrgraph convert_to_csr(const vector<vector<pair<int, int>>>& adjacencyList)
{
    csrgraph csr;

    csr.rowPtr.push_back(0);


    for (int i = 0; i < adjacencyList.size(); i++)
    {
        for (int j = 0; j < adjacencyList[i].size(); j++)
        {
            csr.colIdx.push_back(adjacencyList[i][j].first);
            csr.values.push_back(adjacencyList[i][j].second);
        }

        csr.rowPtr.push_back(csr.colIdx.size());
    }

    return csr;
}
