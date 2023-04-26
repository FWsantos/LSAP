#include "../include/LSAP.h"
#include <algorithm>
#include <iostream>

void LSAP::printTeste() {
    std::cout << "PrintTeste" << std::endl;
}

void LSAP::row_reduction(matrix<int> C, std::vector<int> &u, int n) {
    for (int i = 0; i < n; ++i) {
        u[i] = C[i][0];
        for (int j = 0; j < n; ++j) {
            if(u[i] > C[i][j]) {
                u[i] = C[i][j];
            }
        }
        // std::cout << "u["<< i <<"] = " << u[i]<< "\n";
    }
}

void LSAP::column_reduction(matrix<int> C, std::vector<int> u, std::vector<int> &v, int n) {
    for (int j = 0; j < n; j++) {
        v[j] = C[0][j] - u[0];
        for (int i = 0; i < n; i++) {
            if(v[j] > C[i][j] - u[i]) {
                v[j] = C[i][j] - u[i];
            }
        }
    // std::cout << "v["<< j <<"] = " << v[j]<< "\n";
    }
}

void LSAP::procedure_basic_preprocessing(matrix<int> C, int n, std::vector<int> &row) {
    matrix<int> X(n, std::vector<int>(n, 0));
    std::vector<int> u(n, 0);
    std::vector<int> v(n, 0);
    
    row_reduction(C, u, n);
    column_reduction(C, u, v, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(row[j] == 0 && (C[i][j] - u[i] - v[j]) == 0) {
                X[i][j] = 1;
                row[j] = i+1;
                break;
            }
        }
        
    }
}

void LSAP::procedure_alternate(
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


void LSAP::hungarian_n4(std::set<int> U, int n){
    std::vector<int> u(n, 0);
    std::vector<int> v(n, 0);
    std::vector<int> row(n, 0);
    std::vector<int> phi(n, 0);
    std::set<int> U_;
    std::set<int> U_dif_U_;
    int sink;

    while (U_.size() < n){
        U_dif_U_.clear();
        std::set_difference(U.begin(), U.end(), U_.begin(), U_.end(), std::inserter(U_dif_U_, U_dif_U_.begin()));
                
    }
    
}