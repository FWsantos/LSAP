#include "../include/Tests.h"
#include "../include/LSAP.h"
#include "../include/Utils.h"
#include <iostream>

void Tests::test_procedure_basic_preprocessing(){
    int n;
    // Initialize cost matrix C and get n
    matrix<int> C = Utils::read_file("../file_inputs/basic_test.txt", n);
    
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

void Tests::test_read_file(){
    int n;
    matrix<int> C = Utils::read_file("../file_inputs/basic_test.txt", n);
    std::cout << "n: " << n << std::endl;
}
