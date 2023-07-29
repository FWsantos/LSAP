#include "../include/Tests.h"
#include "../include/LSAP.h"
#include "../include/Preprocess.h"
#include "../include/Utils.h"
#include <algorithm>
#include <iostream>


void Tests::test_generate_phi()
{
    int n = 0;
    // Initialize cost matrix C and get n
    matrix<int> C = Utils::read_file(Tests::file_path, n);
    std::vector<int> u, v;

    std::vector<int> row = Preprocess::feasible_solution(C, u, v, n);
    
    std::cout << "C = ";
    for (int i = 0; i < n; ++i)
    {
        std::cout << "\t";
        for (int j = 0; j < n; ++j)
        {
            std::cout << C[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "row = ";
    for (int i = 0; i < n; ++i){
        std::cout << " " << row[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> phi = LSAP::generate_phi(row);

    std::cout << "phi = ";
    for (int i = 0; i < n; ++i){
        std::cout << " " << phi[i] << " ";
    }
    std::cout << std::endl;
}


void Tests::test_basic_preprocessing()
{
    int n = 0;
    // Initialize cost matrix C and get n
    matrix<int> C = Utils::read_file(Tests::file_path, n);
    std::vector<int> u, v;

    std::vector<int> row = Preprocess::feasible_solution(C, u, v, n);

    std::cout << "C = ";
    for (int i = 0; i < n; ++i)
    {
        std::cout << "\t";
        for (int j = 0; j < n; ++j)
        {
            std::cout << C[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "u = ";
    for (int i = 0; i < n; ++i)
        std::cout << " " << u[i] << " ";
    std::cout << std::endl;

    std::cout << "v = ";
    for (int i = 0; i < n; ++i)
        std::cout << " " << v[i] << " ";
    std::cout << std::endl;

    std::cout << "row = ";
    for (int i = 0; i < n; ++i)
        std::cout << " " << row[i] << " ";
    std::cout << std::endl;
}

void Tests::test_read_file()
{
    int n;
    matrix<int> C = Utils::read_file(Tests::file_path, n);
    std::cout << "n: " << n << std::endl;
}

void Tests::set_test()
{
    struct Vertice
    {
        int value;
        // bool
    };

    std::set<int> set;
    set = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int k = 2;

    // std::for_each(set.cbegin(), set.cend(), [](int x) {
    //     std::cout << x << ' ';
    // });
    for (auto i : set)
    {
        std::cout << i << ' ';
    }

    std::cout << "\n\n\n";
}

void Tests::hungarian()
{
    std::cout << "Hungarian function test begin...\n";
    int n = 0;
    // Initialize cost matrix C and get n
    matrix<int> C = Utils::read_file(Tests::file_path, n);
    Utils::print_matrix(C);

    LSAP::hungarian(C, n);

    Utils::print_matrix(C);

    std::cout << "successful test\n";
}

void Tests::hungarian_v2()
{
    std::cout << "Hungarian function test begin...\n";
    int n = 0;
    // Initialize cost matrix C and get n
    matrix<int> C = Utils::read_file(Tests::file_path, n);
    Utils::print_matrix(C);

    LSAP::hungarian_n4_v2(C, n);

    Utils::print_matrix(C);

    std::cout << "successful test\n";
}