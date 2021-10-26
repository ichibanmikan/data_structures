#include <iostream>
#include"graphADT.h"
#include"graphRealise.h"

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    graphRealise<char> g1(n);
    g1.setType(1);
    char ch;
    for (int i=0; i<n; i++){
        cin >> ch;
        g1.setVex(i, ch);
    }
    int w;
    char ch1, ch2;
    for (int i=0; i<m; i++){
        cin >> ch1 >> ch2 >> w;
        g1.setEdge(g1.locateVex(ch1), g1.locateVex(ch2), w);
    }
    g1.printhelp();
    g1.printMax();
    return 0;
}
