#include "Types.h"
#include <set>

class LSAP
{
public:
    // Find an alternating tree rooted at an unassigned vertex k in U
    static int alternate_k(
        matrix<int> C,
        std::set<int> V,
        std::set<int> &SU,
        std::set<int> &LV,
        std::set<int> &V_diff_LV,
        std::vector<int> u,
        std::vector<int> v,
        std::vector<int> row,
        std::vector<int> &pred,
        int k);

    /* Basic O(n^4) Hungarian algorithm. */
    static void hungarian_n4(matrix<int> C, int n);
    
    // Generate phi vector from row vector.
    static std::vector<int> generate_phi(std::vector<int> row);

private:
    static std::set<int> diff(std::set<int> A, std::set<int> B);
};