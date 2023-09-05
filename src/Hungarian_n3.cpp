#include "../include/LSAP.h"
#include "../include/Preprocess.h"
#include <algorithm>
#include <limits>

// Find an aulgmenting tree rooted at an unassigned vertex k in U
int LSAP::augment_k(
    matrix<int> C,
    std::set<int> V,
    std::set<int> &SU,
    std::set<int> &LV,
    std::set<int> &V_diff_LV,
    std::vector<int> u,
    std::vector<int> v,
    std::vector<int> row,
    std::vector<int> &pred,
    int k)
{
    int int_max = std::numeric_limits<int>::max();
    std::vector<int> pi(V.size(), int_max);

    // SU, SV => Scanned vertices
    // LV => Labbed vertices
    std::set<int> SV;
    SU.clear();
    LV.clear();
    V_diff_LV.clear();

    int sink = -1;
    int i = k;

    while (sink == -1)
    {
        SU.insert(i);

        V_diff_LV = LSAP::diff(V, LV);

        for (const int &j : V_diff_LV)
        {
            if ((C[i][j] - u[i] - v[j]) < pi[j])
            {
                pred[j] = i;
                pi[j] = C[i][j] - u[i] - v[j];
                if (pi[j] == 0)
                    LV.insert(j);
            }
        }

        std::set<int> LV_diff_SV = LSAP::diff(LV, SV);

        if (LV_diff_SV.empty())
        {
            int delta = *V_diff_LV.begin();
            for (const int &j : LV_diff_SV)
                if (j < delta)
                    delta = j;

            for (const int &i : SU)
                u[i] += delta;

            for (const int &j : LV)
                v[j] += delta;

            for (const int &j : V_diff_LV)
            {
                pi[j] -= delta;
                if (pi[j] == 0)
                    LV.insert(j);
            }
        }

        int j = *LV_diff_SV.begin();
        SV.insert(j);
        if (row[j] == -1)
            sink = j;
        else
            i = row[j];
    }

    return sink;
}

/* Basic O(n^3) Hungarian algorithm. */
std::vector<int> LSAP::hungarian_n3(matrix<int> C, int n)
{
    std::vector<int> u, v, row, pred(n, -1), phi(n, -1);
    std::set<int> V, U, U_, SU, LV, V_diff_LV;

    for (int x = 0; x < n; ++x)
    {
        V.insert(x);
        U.insert(x);
    }

    row = Preprocess::feasible_solution(C, u, v, n);
    phi = LSAP::generate_phi(row);

    for (auto &element : row)
        if (element != -1)
            U_.insert(element);

    while (U_.size() < n)
    {
        std::set<int> U_diff_U_ = LSAP::diff(U, U_);

        int k = *U_diff_U_.begin();

        int sink = LSAP::augment_k(
            C, V, SU, LV, V_diff_LV, u, v, row, pred, k);
        U_.insert(k);

        int i, h, j = sink;

        do
        {
            i = pred[j];
            row[j] = i;
            std::swap(phi[i], j);
        } while (i != k);
    }

    return phi;
}