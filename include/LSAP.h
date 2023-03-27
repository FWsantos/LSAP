#include <set>
#include <vector>

/* Matrix type */
typedef std::vector<std::vector<int>> matrix;

class LSAP {
public:
    static void printTeste();
    static void basic_preprocessing(matrix C, matrix &X, std::vector<int> &row, int n);
    static void procedure_alternate(matrix C, std::set<int> V, int k);

private:
    static void row_reduction(matrix C, std::vector<int> &u, int n);
    static void column_reduction(matrix C, std::vector<int> u, std::vector<int> &v, int n);
};