#include "../include/LSAP.h"

#include <algorithm>
#include <limits>

int LSAP::shortest_path(
    matrix<int> C,
    std::vector<int> V,
    std::vector<int> u,
    std::vector<int> v,
    std::vector<int> row,
    std::vector<int> &pred,
    int k)
{
    int int_max = std::numeric_limits<int>::max();
    std::vector<int> pi(V.size(), int_max);

    std::set<int> SU, SV;
    int sink = 0, delta = 0, i = k;

    while (i == 0)
    {
        SU.insert(i);

        std::set<int> V_diff_SV = LSAP::diff(V, SV);

        for (auto &j : V_diff_SV)
        {
            if (delta = C[i][j] - u[i] - v[j] < pi[j])
            {
                pred[j] = i;
                pi[j] = delta + C[i][j] - u[i] - v[j];
            }
        }
    }

    return sink;
}