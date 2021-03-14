#include <iostream>
#include"graphADT.h"
#include"graphRealise.h"
#include <cmath>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    graphRealise<int> g1(n);
    g1.setType(0);
    for (int i=0; i<n; i++){
        g1.setVex(i, i+1);
    }
    int type, t1, t2, dist;
    for (int i=0; i<m; i++){
        cin >> type >> t1 >> t2 >> dist;
        if(type==0){
            g1.setEdge(t1-1, t2-1, dist);
        }
        else{
            g1.setEdge(t1-1, t2-1, pow(dist, 2));
        }
    }
    g1.Dijkstra(0);
    // g1.getAllD();
    cout << g1.getFinalD() << endl;
    system("pause");
    return 0;
}
