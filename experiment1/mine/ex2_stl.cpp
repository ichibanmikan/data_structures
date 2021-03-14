// #include <iostream>
// #include <map>
// #include <sstream>
// #include <cstring>
// #include <vector>

// using namespace std;

// int main()
// {
//     map<int, char> isout;
//     int n, k;
//     cin >> n >> k;
//     stringstream strstm, strstmk;
//     string strno;
//     vector<int> vec;
//     char strk, charno;
//     for (int i=0; i<n; i++)
//     {
//         isout[i]='n';
//         vec.push_back(i);
//     }
//     int numchild=n, ju=0, order=1;   
//     strstmk << k;
//     strstmk >> strk;
//     while (true)
//     {
//         ju=0;
//         for (int j=0; j<numchild; j++)
//         {  
//             if (n==1)
//             {
//                 // for (int i=0; i<numchild; i++)
//                 // {
//                 //     if (isout[i]=='n')
//                 //     {
//                 //         cout << i << endl;
//                 //         break;
//                 //     }
//                 // }
//                 cout << j+1 << endl;
//                 ju=1;
//                 break;
//             } 
//             if (isout[j]=='n')
//             {
//                     if (order<10)
//                     {            
//                         strstm << order;
//                         strstm >> charno;
//                     }
//                     else
//                     {
//                         strstm << order;
//                         strstm >> strno;
//                     }
//                     if (strno[strno.size()-1]==strk||charno==strk)
//                     {
//                         isout[j]='y';
//                         n--;
//                     }
//                     else if (order%k==0)
//                     {
//                         isout[j]='y';
//                         n--;
//                     }
//                     // cout << order << endl;
//                     order++;
//                 // }
//                 cout << order << endl;
//             }
//         }
//         if (ju==1)
//             break;
//     }
//     return 0;

#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
    queue<int> list;
    int k, n=1, sum;
    cin>> sum >> k;
    for(int i=0; i<sum; i++)
    {
        list.push(i);
    }
    while(list.size() > 1)
    {
        int floorvalue;
        floorvalue=list.front();
        list.pop();
        if(n%k!=0 && (n-n/10*10)!=k)
        {
            list.push(floorvalue);
        }
        n++;
    }
    cout << list.front()+1 << endl;;
    return 0;
}