#include "Graph.h"
#include "Graphl.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    Graphl<char> G(n);
    G.setType(1);
    char ch;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        G.setVex(i, ch);
    }
    int w;
    char ch1, ch2;
    for (int i = 0; i < m; i++) {
        cin >> ch1 >> ch2 >> w;
        G.setEdge(G.locateVex(ch1), G.locateVex(ch2), w);
    }
    G.printMatrix();
    G.printMax();
    // G.printVertex();
    return 0;
}
