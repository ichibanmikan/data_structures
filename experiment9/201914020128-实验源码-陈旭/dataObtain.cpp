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
    return 0;
}

/*#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void randperm(int Num)
{
    vector<int> temp;
    for (int i = 0; i < Num; ++i)
    {
        temp.push_back(i + 1);
    }

    random_shuffle(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
}

cout << endl;
*/