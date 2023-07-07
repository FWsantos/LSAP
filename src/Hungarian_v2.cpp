#include "../include/LSAP.h"
#include "../include/Preprocess.h"
#include <algorithm>
#include <iostream>


std::set<int> LSAP::diff(std::set<int> A, std::set<int> B)
{
    std::set<int> A_diff_B;
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::inserter(A_diff_B, A_diff_B.begin()));
    return A_diff_B;
}

std::vector<int> LSAP::generate_phi(std::vector<int> row)
{
    std::vector<int> phi (row.size(), 0);
    for (int j = 0; j < row.size(); ++j)
    {
        if (row[j] != 0)
        {
            phi[row[j] - 1] = j +1;
        }
    }

    return phi;
}


// define LSAP through a graph theory model. Define a bipartite
// graph G = (U, V ; E) having a vertex of U for each row, a vertex of V for
// each column, and cost cij associated with edge [i, j ] (i, j = 1, 2,...,n):
// The problem is then to determine a minimum cost perfect matching in G
// (weighted bipartite matching problem: find a subset of edges such that each
// vertex belongs to exactly one edge and the sum of the costs of these edges
// is a minimum)

// Find an alternating tree rooted at an unassigned vertex k into U
int LSAP::alternate_k_v2(
    matrix<int> C,
    std::set<int> V,
    std::set<int> &SU,
    std::set<int> &LV,
    std::set<int> &V_diff_LV,
    std::vector<int> u,
    std::vector<int> v,
    std::vector<int> row,
    std::vector<int> &pred,
    int k)
{
    // SU, SV => Scanned vertices
    // LV => Labbed vertices
    std::set<int> SV;
    bool fail = false;

    // Sink is return about function
    int sink = 0;
    int i = k;


    while (fail == false && sink == 0)
    {
        // Scanning vertex i
        SU.insert(i);
        // V_diff_LV = V\LV
        V_diff_LV = LSAP::diff(V, LV);


        for (auto j_iterator = V_diff_LV.begin(); j_iterator != V_diff_LV.end(); ++j_iterator)
        {
            int j = *j_iterator;
            if ((C[i][j] -u[i] -v[j]) == 0)
            {

                pred[j] = i;
                LV.insert(j);

            }
        }
3   
        std::set<int> LV_diff_SV = LSAP::diff(V, LV);

        if(LV_diff_SV.empty()){
            fail = true;
        }else {
            int j = *LV_diff_SV.begin();
            SV.insert(j);
            if(row[j] == 0) {
                sink = j;
            } else {
                i = row[j] - 1;
            }
        }
    }

    return sink;
}

void LSAP::hungarian_n4_v2(matrix<int> C, int n) 
{
    std::vector<int> u, v, row, pred(n, 0), phi(n,0);
    std::set<int> V, U, U_, SU, LV, V_diff_LV;

    for (int x = 0; x < n; ++x){
        V.insert(x);
        U.insert(x);
    }

    row = Preprocess::feasible_solution(C, u, v, n);
    phi = LSAP::generate_phi(row);
    
    while(U_.size() < n){
        std::set<int> U_diff_U_ = LSAP::diff(U, U_);
        
        int k = *U_diff_U_.begin();


        while(!U_.contains(k)){
            int sink = LSAP::alternate_k_v2(C, V, SU, LV, V_diff_LV, u, v, row, pred, k);

            if(sink > 0){
                U_.insert(k);
                
                int i, h, j = sink;

                do{
                    i = pred[j];
                    row[j] = i;
                    h = phi[i];
                    phi[i] = j;
                    j = h;
                } while(i != k);

            } else {
                int delta = 0;
                for (auto i = SU.begin(); i != SU.end(); ++i){
                    for (auto j = V_diff_LV.begin(); j != V_diff_LV.end(); ++j){
                        if ((C[*i][*j] - u[*i] -v[*j]) < delta){
                            delta = C[*i][*j] - u[*i] -v[*j];                       
                        }
                    }
                }

                for (auto i = SU.begin(); i != SU.end(); ++i){
                    u[*i] = u[*i] + delta;
                }
                for (auto j = LV.begin(); j != LV.end(); ++j){
                    v[*j] = v[*j] - delta;
                }
            }
        }
    }
}

