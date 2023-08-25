#include "Types.h"

/*
    @brief Preprocessing phase to determine a feasible dual solution and a partial primal solution (where less than n rows are assigned) satisfying the complementary slackness conditions.
 */
class Preprocess
{

public:
    /*
        @brief Generates feasible solution in O(n^2) time.

        @param C: Cost matrix.
        @param u: Copy by reference of vector u and is fill with row reduction.
        @param u: Copy by reference of vector v and is fill with column reduction.
        @param n: Number of rows and columns in the matrix C.


        @return Vector that represents the columns of the matrix. Each element stores the row to which the column is assigned.  If it is not assigned to anyone, the value is 0.
     */
    static std::vector<int> feasible_solution(
        matrix<int> C,
        std::vector<int> &u,
        std::vector<int> &v,
        int n);

private:
    /*
        @brief Get mininum value for each row in matrix C.
        @param C: Cost matrix;
        @param n: Number of rows and columns in the matrix C

        @return Vector that stores mininum value for each row in matrix C.
     */
    static std::vector<int> row_reduction(
        matrix<int> C, int n);
    /*
        @brief Get mininum C[i][j]-u[i] for each column in matrix C.
        @param C: Cost matrix;
        @param u: Vector with minimun value of each row in matrix C;
        @param n: Number of rows and columns in the matrix C

        @return Vector that stores mininum C[i][j]-u[i] for each column in matrix C.
     */
    static std::vector<int> column_reduction(
        matrix<int> C,
        std::vector<int> u,
        int n);
};
