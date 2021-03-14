#include "Amylist.h"
#include <iostream>
#include "mylist.h"
#include <cmath>

using namespace std;

int main()
{
    int n, num;
    cin >> n;
    Amylist<int> vec_num;
    for (int i=0; i<n; i++)
    {
        cin >> num;
        vec_num.append(num);
    }
    vec_num.setorder();
    int temp, temp1;
    vec_num.movetostart();
    for (int i=0; i<vec_num.length()-1; i++)
    {
        if (i==0)
        {
            temp1=vec_num.getvalue();
            vec_num.next();
            temp=abs(vec_num.getvalue()-temp1);
        }
        else
        {
            temp1=vec_num.getvalue();
            vec_num.next();
            if (abs(vec_num.getvalue()-temp1)<temp)
                temp=abs(vec_num.getvalue()-temp1);
        }
    }
    cout << temp << endl;
    return 0;
}