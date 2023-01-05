#include <set>
#include <vector>

class LSAP {
public:
    static int teste(int te);
    static void basic_preprocessing(std::vector<std::vector<int>> C, std::vector<std::vector<int>> &X, std::vector<int> &row, int n);
    static void procedure_alternate(std::vector<std::vector<int>> C, std::set<int> V, int k);

private:
    static void row_reduction(std::vector<std::vector<int>> C, std::vector<int> &u, int n);
    static void column_reduction(std::vector<std::vector<int>> C, std::vector<int> u, std::vector<int> &v, int n);
};