#include <iostream>
#include "include/LSAP.h"

void test_procedure_basic_preprocessing(){
    int n = 4;
    // Initialize cost matrix C
    matrix C = {
        {7, 9, 8, 9},
        {2, 8, 5, 7},
        {1, 6, 6, 9},
        {3, 6, 2, 2},
    };
    // Initialize resulting vector row
    std::vector<int> row(n, 0);

    LSAP::procedure_basic_preprocessing(C, n, row);

    std::cout << "C = ";
    for (int i = 0; i < n; ++i) {
        std::cout << "\t";
        for (int j = 0; j < n; ++j){
            std::cout << C[i][j] << " ";
        }
            std::cout << std::endl;
    }

    std::cout << "row = ";
    for (int i = 0; i < n; ++i)
        std::cout << " " << row[i] << " ";
    std::cout << std::endl;

}

int main(int argc, char const *argv[])
{
    test_procedure_basic_preprocessing();
    return 0;
}
