#include <iostream>
#include <assert.h>
#include <cstring>
#include "mybitree.h"
#include "realisemybitree.h"

using namespace std;

realisemylinkbitree<char> chtree;
int size=0;
string str, str1, str2;
int n;

int main(){
    int pos;
    cin >> n;
    getchar();
    getline(cin, str1);
    getline(cin, str2);
    for (int i=0; i<str1.size(); i++){
        if (str1[i]==' '){
            str1.erase(i, 1);
        }
        if (str2[i]==' '){
            str2.erase(i, 1);
        }
        if (str2[i]==str1[str1.size()-1]){
            pos=i;
        }
    }
    chtree.setroot(chtree.build(str2, str1));
    chtree.levelorder(chtree.getroot());
    system("pause");
    return 0;
}
