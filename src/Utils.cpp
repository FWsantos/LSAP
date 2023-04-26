#include "../include/Utils.h"
#include <fstream>
#include <iostream>
#include <sstream>


void Utils::read_file(std::string file_path, matrix<int> &C, int &n){
    
    std::ifstream file(file_path);
    
    std::string line, value;
    std::getline(file, line);
    std::stringstream stream_value (line);
    stream_value >> value;
    n = std::stoi(value);
    while (std::getline(file, line)){
        std::cout << line << std::endl;
    }
    
    file.close();
}
