#include "Types.h"
#include <string>
#include <set>

class Utils
{
private:
    /* data */
public:
    static matrix<int> read_file(std::string file_path, int &n);
    static void print_matrix(matrix<int> M, std::string name = "");
    static void print_vector(std::vector<int> V, std::string name = "");
    static void print_set(std::set<int> S, std::string name = "");
};