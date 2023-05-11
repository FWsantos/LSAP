#include "../include/Preprocess.h"

std::vector<int> Preprocess::feasible_solution(matrix<int> C, int n)
{
    // initialize u and v vectors
    std::vector<int> u = row_reduction(C, n);
    std::vector<int> v = column_reduction(C, u, n);

    std::vector<int> row(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[j] == 0 && (C[i][j] - u[i] - v[j]) == 0)
            {
                row[j] = i + 1;
                break;
            }
        }
    }
    return row;
}

std::vector<int> Preprocess::row_reduction(matrix<int> C, int n)
{
    std::vector<int> u(n, 0);
    for (int i = 0; i < n; ++i)
    {
        u[i] = C[i][0];
        for (int j = 0; j < n; ++j)
        {
            if (u[i] > C[i][j])
            {
                u[i] = C[i][j];
            }
        }
    }
    return u;
}

std::vector<int> Preprocess::column_reduction(matrix<int> C, std::vector<int> u, int n)
{
    std::vector<int> v(n, 0);
    for (int j = 0; j < n; j++)
    {
        v[j] = C[0][j] - u[0];
        for (int i = 0; i < n; i++)
        {
            if (v[j] > C[i][j] - u[i])
            {
                v[j] = C[i][j] - u[i];
            }
        }
    }
    return v;
}