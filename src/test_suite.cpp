#include "../include/LSAP.h"
#include "../include/Tests.h"
#include "../include/Utils.h"

#include <iostream>

void Tests::assign_files()
{
    int n;
    std::cout << "Data file\tResult solution value\n";
    for (int i = 1; i <= 1; i++)
    {
        std::string file_name = "assign" + std::to_string(i) + "00";
        matrix<int> C = Utils::read_file("../file_inputs/" + file_name + ".txt", n);

        // Utils::print_matrix(C);
        // std::cout << "n = " << n << "\n";
        std::vector<int> phi = LSAP::hungarian_sp(C, n);

        Utils::print_vector(phi, "phi");
        // int result = 0;
        // std::cout << "phi = ";
        // for (int i = 0; i < n; i++)
        //     std::cout << phi[i] + ", ";
        // std::cout << "\n\n";
        // result += C[i][phi[i]];

        // std::cout << file_name << "\t" << result << "\n";
    }

    std::cout << "\nTest end.\n";
}
