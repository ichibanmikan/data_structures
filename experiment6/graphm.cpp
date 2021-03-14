#include <iostream>
#include"graphADT.h"
#include"graphRealise.h"

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    graphRealise<int> g1(n);
    g1.setType(1);
    for (int i=0; i<n; i++){
        g1.setVex(i, i+1);
    }
    int t1, t2;
    for (int i=0; i<m; i++){
        cin >> t1 >> t2;
        g1.setEdge(t1-1, t2-1, 0);
    }
    for (int i=0; i<n; i++){
        g1.setEdge(i, i, 0);
    }
    // g1.printmatrix();
    g1.setComnetwork();
    g1.delComnetWork();
    cout << g1.allKnow() << endl;
    return 0;
}