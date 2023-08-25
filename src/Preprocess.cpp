#include "../include/Preprocess.h"

std::vector<int> Preprocess::feasible_solution(
    matrix<int> C,
    std::vector<int> &u,
    std::vector<int> &v,
    int n)
{
    // initialize u and v vectors
    u = row_reduction(C, n);
    v = column_reduction(C, u, n);

    std::vector<int> row(n, -1);
    for (int i = 0; i < n; i++)
    {
        bool stop = false;
        for (int j = 0; j < n; j++)
        {
            C[i][j] = C[i][j] - u[i] - v[j];
            if (row[j] == -1 && C[i][j] == 0 && !stop)
            {
                row[j] = i;
                stop = true;
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