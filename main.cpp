#include <iostream>
#include "include/LSAP.h"

int main(int argc, char const *argv[])
{

    int n = 4;
    std::vector<std::vector<int>> C = {
        {7, 9, 8, 9},
        {2, 8, 5, 7},
        {1, 6, 6, 9},
        {3, 6, 2, 2},
    };
    std::vector<std::vector<int>> X(n, std::vector<int>(n, 0));
    std::vector<int> row(n, 0);
    std::cout << "row = ";
    for (int i = 0; i < n; ++i)
        std::cout << " " << row[i] << " ";
    std::cout << std::endl;

    LSAP::basic_preprocessing(C, X, row, n);

    // int C[n][n] = {{1,2}, {3,4}};

    std::cout << "C = ";
    for (int i = 0; i < n; ++i) {
        std::cout << "\t";
        for (int j = 0; j < n; ++j){
            std::cout << C[i][j] << " ";
        }
            std::cout << std::endl;
    }

    std::cout << "X = ";
    for (int i = 0; i < n; ++i) {
        std::cout << "\t";
        for (int j = 0; j < n; ++j){
            std::cout << X[i][j] << " ";
        }
            std::cout << std::endl;
    }
    std::cout << "row = ";
    for (int i = 0; i < n; ++i)
        std::cout << " " << row[i] << " ";
    std::cout << std::endl;

    return 0;
}
