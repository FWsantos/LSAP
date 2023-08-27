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

    Utils::print_matrix(C, "C");
    Utils::print_vector(u, "u");
    Utils::print_vector(v, "v");
    Utils::print_vector(row, "row");

    std::vector<int> phi = LSAP::generate_phi(row);

    Utils::print_vector(phi, "phi");
}

void Tests::test_basic_preprocessing()
{
    int n = 0;
    // Initialize cost matrix C and get n
    matrix<int> C = Utils::read_file(Tests::file_path, n);
    std::vector<int> u, v;

    std::vector<int> row = Preprocess::feasible_solution(C, u, v, n);

    Utils::print_matrix(C, "C");
    Utils::print_vector(u, "u");
    Utils::print_vector(v, "v");
    Utils::print_vector(row, "row");
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

void Tests::test_alternate_k()
{
    std::cout << "Alternate_k function test begin...\n";

    int n = 0;

    // Initialize cost matrix C and get n
    matrix<int> C = Utils::read_file(Tests::file_path, n);
    std::vector<int> u, v;

    std::vector<int> row = Preprocess::feasible_solution(C, u, v, n);
    Utils::print_matrix(C, "C");
    Utils::print_vector(u, "u");
    Utils::print_vector(v, "v");
    Utils::print_vector(row, "row");

    std::set<int> V;
    for (int i = 0; i < n; i++)
        V.insert(i);

    std::set<int> SU;
    std::set<int> LV;
    std::set<int> V_diff_LV;
    std::vector<int> pred(n, -1);
    int k = 1;

    int sink = LSAP::alternate_k(
        C,
        V,
        SU,
        LV,
        V_diff_LV,
        u,
        v,
        row,
        pred,
        k);

    std::cout << "sink = " << sink << "\n";
}

void Tests::hungarian_n4()
{
    std::cout << "Hungarian function test begin...\n";
    int n = 0;
    // Initialize cost matrix C and get n
    matrix<int> C = Utils::read_file(Tests::file_path, n);
    Utils::print_matrix(C);

    std::vector<int> phi = LSAP::hungarian_n4(C, n);

    Utils::print_vector(phi, "phi");
    int result = 0;
    for (int i = 0; i < n; i++)
        result += C[i][phi[i]];

    std::cout << "The result is: " << result << "\n\n";

    std::cout << "Hungarian function test end.\n";
}