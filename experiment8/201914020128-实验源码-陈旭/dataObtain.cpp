#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

// #define max 1000;

int main(){
    vector<int> vec;
    ofstream outfile("data.txt", ios::out);
    for (int i=0; i<1000; i++){
        vec.push_back(i+1);
    }
    random_shuffle(vec.begin(), vec.end());
    for (int i=0; i<1000; i++){
        outfile << vec[i] << ' ';
    }
    outfile.close();
    return 0;
}