#include "../include/LSAP.h"
#include <algorithm>
#include <iostream>

// define LSAP through a graph theory model. Define a bipartite
// graph G = (U, V ; E) having a vertex of U for each row, a vertex of V for
// each column, and cost cij associated with edge [i, j ] (i, j = 1, 2,...,n):
// The problem is then to determine a minimum cost perfect matching in G
// (weighted bipartite matching problem: find a subset of edges such that each
// vertex belongs to exactly one edge and the sum of the costs of these edges
// is a minimum)

// Find an alternating tree rooted at an unassigned vertex k into U
int LSAP::alternate_k_v2(matrix<int> C, int k)
{
    // SU, SV => Scanned vertices
    // LV => Labbed vertices
    std::set<int> SU, LV, SV;
    bool fail = false;

    // Sink is return about function
    int sink = 0;
    int i = k;

    while (fail == false && sink == 0)
    {
        SU.insert(i);
    }
    return sink;
}
