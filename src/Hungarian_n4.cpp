#include "../include/LSAP.h"
#include "../include/Preprocess.h"
#include <algorithm>

// define LSAP through a graph theory model. Define a bipartite
// graph G = (U, V ; E) having a vertex of U for each row, a vertex of V for
// each column, and cost cij associated with edge [i, j ] (i, j = 1, 2,...,n):
// The problem is then to determine a minimum cost perfect matching in G
// (weighted bipartite matching problem: find a subset of edges such that each
// vertex belongs to exactly one edge and the sum of the costs of these edges
// is a minimum)

// Find an alternating tree rooted at an unassigned vertex k into U
int LSAP::alternate_k(
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
    // SU, SV => Scanned vertices
    // LV => Labbed vertices
    std::set<int> SV;
    SU.clear();
    LV.clear();
    V_diff_LV.clear();

    bool fail = false;

    int sink = -1;
    int i = k;

    while (fail == false && sink == -1)
    {
        // Scanning vertex i
        SU.insert(i);

        // V_diff_LV = V\LV
        V_diff_LV = LSAP::diff(V, LV);

        for (const int &j : V_diff_LV)
        {
            if ((C[i][j] - u[i] - v[j]) == 0)
            {
                pred[j] = i;
                LV.insert(j);
            }
        }

        std::set<int> LV_diff_SV = LSAP::diff(LV, SV);

        if (LV_diff_SV.empty())
        {
            fail = true;
        }
        else
        {
            int j = *LV_diff_SV.begin();
            SV.insert(j);

            if (row[j] == -1)
                sink = j;
            else
                i = row[j];
        }
    }

    return sink;
}

std::vector<int> LSAP::hungarian_n4(matrix<int> C, int n)
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

    for (const int &element : row)
        if (element != -1)
            U_.insert(element);

    while (U_.size() < n)
    {
        std::set<int> U_diff_U_ = LSAP::diff(U, U_);

        int k = *U_diff_U_.begin();

        while (!U_.contains(k))
        {
            int sink = LSAP::alternate_k(
                C, V, SU, LV, V_diff_LV, u, v, row, pred, k);

            if (sink > -1)
            {
                U_.insert(k);

                int i, h, j = sink;

                do
                {
                    i = pred[j];
                    row[j] = i;
                    std::swap(phi[i], j);
                } while (i != k);
            }
            else
            {
                int delta = 0;

                for (const int &i : SU)
                {
                    for (const int &j : V_diff_LV)
                    {
                        int delta_ = C[i][j] - u[i] - v[j];

                        if (i == *SU.begin() && j == *V_diff_LV.begin())
                            delta = delta_;

                        delta = std::min(delta, delta_);
                    }
                }

                for (const int &i : SU)
                    u[i] += delta;
                for (const int &j : LV)
                    v[j] -= delta;
            }
        }
    }

    return phi;
}
