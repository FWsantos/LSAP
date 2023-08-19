#include "../include/Utils.h"
#include <fstream>
#include <iostream>
#include <sstream>

matrix<int> Utils::read_file(std::string file_path, int &n)
{

    std::ifstream file(file_path);

    if (!file.is_open())
    {
        std::cout << "File not found" << std::endl;
        // Emmit Error
    }

    std::string line, value;
    std::getline(file, line);
    std::stringstream stream_value(line);
    stream_value >> value;
    n = std::stoi(value);

    matrix<int> C;
    while (std::getline(file, line))
    {
        std::vector<int> v_line;
        std::stringstream stream_line(line);

        while (stream_line >> value)
            v_line.push_back(std::stoi(value));

        C.push_back(v_line);
    }

    file.close();
    return C;
}

void Utils::print_matrix(matrix<int> M, std::string name)
{
    if(!name.empty())
        std::cout << name << "= \n";

    for (auto &row : M)
    {
        for (auto &element : row)
            std::cout << element << "\t";
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

void Utils::print_vector(std::vector<int> V, std::string name)
{
    if(!name.empty())
        std::cout << name << "= \n";

    for (auto &element: V)
        std::cout << element << "\t";
    std::cout << "\n\n";    
}

void Utils::print_set(std::set<int> S, std::string name)
{
    if(!name.empty())
        std::cout << name << "= \n";

    for (auto iterator = S.begin(); iterator != S.end(); ++iterator)
        std::cout << " " << *iterator << " ";
    std::cout << "\n\n";
}