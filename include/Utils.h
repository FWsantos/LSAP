#include "Types.h"
#include <string>

class Utils
{
private:
    /* data */
public:
    static matrix<int> read_file(std::string file_path, int &n);
    static void print_matrix(matrix<int> C);
};