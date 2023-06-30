#include "Types.h"
#include <set>

class LSAP
{
public:
    // Find an alternating tree rooted at an unassigned vertex k in U
    static int alternate_k(
        matrix<int> C,
        std::set<int> V,
        std::vector<int> u,
        std::vector<int> v,
        std::vector<int> row,
        int k,
        int n);
    
    static void generate_phi(std::vector<int> row, std::vector<int> &phi);

    // Basic Hungarian algorithm based on https://hungarianalgorithm.com.
    static void hungarian(matrix<int> &C, int n);

    /* Basic O(n^4) Hungarian algorithm. */
    static void hungarian_n4(matrix<int> C,
                             std::set<int> V, std::set<int> U, int n);

    // Find an alternating tree rooted at an unassigned vertex k in U
    static int alternate_k_v2(matrix<int> C, std::set<int> V, int k);
    /* Basic O(n^4) Hungarian algorithm. */
    static void hungarian_n4_v2(matrix<int> C, int n);
private:
};