#include "../include/LSAP.h"
#include <algorithm>
#include <iostream>

void LSAP::alternate(
    matrix<int> C,
    std::set<int> V,
    std::vector<int> u,
    std::vector<int> v,
    std::vector<int> row,
    int k,
    int n,
    int &sink
) {
    std::set<int> SU, LV, SV, V_dif_LV, LV_dif_SV;
    std::vector<int> pred;
    bool fail = false;
    // int sink = 0;
    int i = k;

    while(fail == false && sink == 0) {
        SU.insert(i);

        std::set_difference(V.begin(), V.end(), LV.begin(), LV.end(), std::inserter(V_dif_LV, V_dif_LV.begin()));

        for (
            int j = 0;
            j < static_cast<int>(V_dif_LV.size() || C[i][j] - u[i] - v[j] == 0);
            j++
        ) {
            pred[j] = i;
            LV.insert(j);
        }

        std::set_difference(LV.begin(), LV.end(), SV.begin(), SV.end(), std::inserter(LV_dif_SV, LV_dif_SV.begin()));
        if (LV_dif_SV.empty()) {
            fail = true;
        } else {
            std::for_each(LV_dif_SV.begin(), LV_dif_SV.end(), [&](const int& j){
                SV.insert(j);
                if(row[j] == 0){
                    sink = j;
                }else{
                    i = row[j];
                }
            });
        }
    }
}

void LSAP::generate_phi(std::vector<int> row, std::vector<int> &phi){
    
}


void LSAP::hungarian_n4(
    matrix<int> C,
    std::set<int> V,
    std::set<int> U,
    int n
){
    std::vector<int> u(n, 0);
    std::vector<int> v(n, 0);
    std::vector<int> row(n, 0);
    std::vector<int> pred(n, 0);
    std::vector<int> phi(n, 0);

    // U_ is the set of vertices already reached
    std::set<int> U_;
    std::set<int> U_dif_U_;
    std::set<int> V_dif_LV_;
    std::set<int> SU, LV;
    int sink, k, j = 0, i = 0, delta, h;

    while (U_.size() < n){
        U_dif_U_.clear();
        std::set_difference(U.begin(), U.end(), U_.begin(), U_.end(), std::inserter(U_dif_U_, U_dif_U_.begin()));
        
        // let k  be any vertex in U \ U_
        k = *U_dif_U_.begin();
        while (!U_.contains(k)){
            alternate(C, V, u, v, row, k, n, sink);

            if(sink == 0) {
                // increase the primal solution
                U_.insert(k);
                j = sink;

                do {
                    i = pred[j];
                    row[j] = i;
                    h = phi[i];
                    phi[i] = j;
                    j = h;
                } while (i == k);
            } else {
                // update the dual solution
                delta = C[*SU.begin()][*V_dif_LV_.begin()];

                for (auto i : SU) {
                    for (auto j : V_dif_LV_) {
                        if ((C[i][j] - u[i] - v[j]) < delta){
                            delta = C[i][j] - u[i] - v[j];
                        }
                    }        
                }

                for (auto i : SU) {
                    u[i] = u[i] + delta;
                }
                for (auto j : LV) {
                    v[j] = v[j] - delta;
                }                                
            }
        }
        
    }
    
}