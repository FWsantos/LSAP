#include "../include/LSAP.h"
#include "../include/Preprocess.h"
#include "../include/Utils.h"
#include <algorithm>

std::set<int> LSAP::diff(std::set<int> A, std::set<int> B)
{
    std::set<int> A_diff_B;
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::inserter(A_diff_B, A_diff_B.begin()));
    return A_diff_B;
}

std::vector<int> LSAP::generate_phi(std::vector<int> row)
{
    std::vector<int> phi(row.size(), -1);
    for (int j = 0; j < row.size(); ++j)
    {
        if (row[j] != -1)
        {
            phi[row[j]] = j;
        }
    }

    return phi;
}
