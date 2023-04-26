#include "Types.h"
#include <set>

class LSAP {
public:
    static void printTeste();
    static void procedure_basic_preprocessing(
        matrix<int> C,
        int n,
        std::vector<int> &row
    );
    static void procedure_alternate(
        matrix<int> C,
        std::set<int> V,
        std::vector<int> u,
        std::vector<int> v,
        std::vector<int> row,
        int k,
        int n,
        int &sink
    );
    static void generate_phi(std::vector<int> row, std::vector<int> &phi);

    /* Basic O(n^4) Hungarian algorithm. */
    static void hungarian_n4(std::set<int> U, int n);

private:
    static void row_reduction(
        matrix<int> C,
        std::vector<int> &u,
        int n
    );
    static void column_reduction(
        matrix<int> C,
        std::vector<int> u,
        std::vector<int> &v,
        int n
    );
};