#include "../include/LSAP.h"
#include <algorithm>
#include <iostream>

void LSAP::hungarian(matrix<int> &C, int n)
{
    // Step 1: Subtract row minima
    // For each row, find the lowest element and subtract it from each element in that row.

    // Lambda function that receive row reference.
    auto change_rows = [](auto &row)
    {
        // Get minimum value in row.
        int min = *std::min_element(row.begin(), row.end());

        // Decrement minimum value for each element in the row.
        for (auto &element : row)
            element -= min;
    };

    // Execute changes_row lambda for each row in the C matrix.
    std::for_each(C.begin(), C.end(), change_rows);

    // Step 2: Subtract column minima
    // Similarly, for each column, find the lowest element and subtract it from each element in
    // that column.
    for (int col = 0; col < n; col++)
    {
        std::vector<int> column;
        for (const auto &row : C)
            column.push_back(row[col]);

        int min = *std::min_element(column.begin(), column.end());

        if (min > 0)
            for (auto &row : C)
                row[col] -= min;
    }

    // Step 3: Cover all zeros with a minimum number of lines
    // Cover all zeros in the resulting matrix using a minimum number of horizontal and vertical
    // lines. If n lines are required, an optimal assignment exists among the zeros. The algorithm
    // stops.
    // If less than n lines are required, continue with Step 4.
    int xzero = 0;
    int yzero = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (C[i][j] == 0)
            {
                xzero++;
                if (xzero == 2)
                    break;
            }
            if (C[j][i] == 0)
            {
                yzero++;
                if (yzero == 2)
                    break;
            }
        }
        if (xzero == 2 || yzero == 2)
        {
            std::cout << "More that one zero by row or by column.\n";
            break;
        }
        else
        {
            xzero = 0;
            yzero = 0;
        }
    }
}

int LSAP::alternate_k(
    matrix<int> C,
    std::set<int> V,
    std::vector<int> u,
    std::vector<int> v,
    std::vector<int> row,
    int k,
    int n)
{
    std::set<int> SU, LV, SV, V_dif_LV, LV_dif_SV;
    std::vector<int> pred;
    bool fail = false;
    int sink = 0;
    int i = k;

    while (fail == false && sink == 0)
    {
        SU.insert(i);

        std::set_difference(V.begin(), V.end(), LV.begin(), LV.end(), std::inserter(V_dif_LV, V_dif_LV.begin()));

        for (
            int j = 0;
            j < static_cast<int>(V_dif_LV.size() || C[i][j] - u[i] - v[j] == 0);
            j++)
        {
            pred[j] = i;
            LV.insert(j);
        }

        std::set_difference(LV.begin(), LV.end(), SV.begin(), SV.end(), std::inserter(LV_dif_SV, LV_dif_SV.begin()));
        if (LV_dif_SV.empty())
        {
            fail = true;
        }
        else
        {
            std::for_each(LV_dif_SV.begin(), LV_dif_SV.end(), [&](const int &j)
                          {
                SV.insert(j);
                if(row[j] == 0){
                    sink = j;
                }else{
                    i = row[j];
                } });
        }
    }
    return sink;
}

void LSAP::hungarian_n4(
    matrix<int> C,
    std::set<int> V,
    std::set<int> U,
    int n)
{
    std::vector<int> u(n, 0);
    std::vector<int> v(n, 0);
    std::vector<int> row(n, 0);
    std::vector<int> pred(n, 0);
    std::vector<int> phi(n, 0);

    // U_ is the set of vertices already reached
    std::set<int> U_;
    std::set<int> U_dif_U_;
    std::set<int> V_dif_LV_;
    std::set<int> SU, LV;
    int sink, k, j = 0, i = 0, delta, h;

    while (U_.size() < n)
    {
        U_dif_U_.clear();
        std::set_difference(U.begin(), U.end(), U_.begin(), U_.end(), std::inserter(U_dif_U_, U_dif_U_.begin()));

        // let k  be any vertex in U \ U_
        k = *U_dif_U_.begin();
        while (!U_.contains(k))
        {
            sink = alternate_k(C, V, u, v, row, k, n);

            if (sink == 0)
            {
                // increase the primal solution
                U_.insert(k);
                j = sink;

                do
                {
                    i = pred[j];
                    row[j] = i;
                    h = phi[i];
                    phi[i] = j;
                    j = h;
                } while (i == k);
            }
            else
            {
                // update the dual solution
                delta = C[*SU.begin()][*V_dif_LV_.begin()];

                for (auto i : SU)
                {
                    for (auto j : V_dif_LV_)
                    {
                        if ((C[i][j] - u[i] - v[j]) < delta)
                        {
                            delta = C[i][j] - u[i] - v[j];
                        }
                    }
                }

                for (auto i : SU)
                {
                    u[i] = u[i] + delta;
                }
                for (auto j : LV)
                {
                    v[j] = v[j] - delta;
                }
            }
        }
    }
}
