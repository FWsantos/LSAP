#include <algorithm>
#include <iostream>
#include "../include/LSAP.h"

void LSAP::printTeste() {
    std::cout << "PrintTeste" << std::endl;
}

void LSAP::row_reduction(matrix C, std::vector<int> &u, int n) {
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

void LSAP::column_reduction(matrix C, std::vector<int> u, std::vector<int> &v, int n) {
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

void LSAP::basic_preprocessing(matrix C, matrix &X, std::vector<int> &row, int n) {
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

void procedure_alternate(
    matrix C,
    std::set<int> V,
    std::vector<int> u,
    std::vector<int> v,
    std::vector<int> row,
    int &sink,
    int k,
    int n
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


