#include "../include/LSAP.h"
#include "../include/Preprocess.h"

#include <algorithm>
#include <limits>

int LSAP::shortest_path(
    matrix<int> C,
    std::set<int> V,
    std::vector<int> u,
    std::vector<int> v,
    std::vector<int> row,
    std::vector<int> phi,
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

        std::set<int> V_diff_SV = diff(V, SV);

        int arg_min = int_max;

        for (const int &j : V_diff_SV)
        {
            if (delta = C[i][j] - u[i] - v[j] < pi[j])
            {
                pred[j] = i;
                pi[j] = delta + C[i][j] - u[i] - v[j];
            }

            // Get min pi[j] , j => V/SV
            if (pi[j] < arg_min)
            {
                arg_min = pi[j];
            }
        }

        int j = arg_min;

        SV.insert(j);
        delta = pi[j];

        if (row[j] == -1)
        {
            sink = j;
        }
        else
        {
            i = row[j];
        }
    }

    // dual update
    u[k] = u[k] + delta;
    for (const int &i : SU)
    {
        if (i != k)
        {
            u[i] = u[i] + delta - pi[phi[i]];
        }
    }

    for (const int &j : SV)
    {
        v[j] = v[j] - delta + pi[j];
    }

    return sink;
}

std::vector<int> LSAP::hungarian_sp(matrix<int> C, int n)
{
    std::vector<int> u, v, row, pred(n, -1), phi(n, -1);
    std::set<int> V, U, U_, SU, LV, V_diff_LV;

    for (int x = 0; x < n; ++x)
    {
        V.insert(x);
        U.insert(x);
    }

    row = Preprocess::feasible_solution(C, u, v, n);
    phi = generate_phi(row);

    for (const int &element : row)
    {
        if (element != -1)
        {
            U_.insert(element);
        }
    }

    while (U_.size() < n)
    {
        std::set<int> U_diff_U_ = diff(U, U_);
        int k = *U_diff_U_.begin();
        int sink = shortest_path(C, V, u, v, row, phi, pred, k);

        U_.insert(k);
        int i, h, j = sink;

        do
        {
            i = pred[j];
            row[j] = i;
            h = phi[i];
            phi[i] = j;
            j = h;
        } while (i != k);
    }

    return phi;
}
