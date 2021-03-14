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

// realisemybitreenode<char>* createbitree(char ch)
// {
//     realisemybitreenode<char>* it;
//     if (ch=='#')
//     {
//         it = NULL;
//     }
//     else
//     {
//         it = new realisemybitreenode<char>; /**/
//         it->setelement(ch);
//         ch=str[++size];
//         it->setleft(createbitree(ch));
//         ch=str[++size];
//         it->setright(createbitree(ch));
//     }
// 	chtree.setroot(it);
//     return it;
// }


// void getpreorder(string s1, string s2)
// {
// 	if (n==0)
// 		return;
// 	else if (n==1)
// 	{
// 		str=s2[0];
// 		return ;
// 	}
// 	int position=s2.find(s2[n-1]);
// 	str+=s1[n-1]; 
// 	getpreorder(s2.substr(0, position + 1),  s1.substr(0, position));
// 	getpreorder(s2.substr(position+1, n-position-1), s1.substr(position, n-position-1));
// }

int main()
{
    int pos;
    cin >> n;
    getchar();
    getline(cin, str1);
    // getline(cin, str2);
    for (int i=0; i<str1.size(); i++)
    {
        if (str1[i]==' ')
        {
            str1.erase(i, 1);
        }
        // if (str2[i]==' ')
        // {
        //     str2.erase(i, 1);
        // }
        // if (str2[i]==str1[str1.size()-1])
        // {
        //     pos=i;
        // }
    } //将顺序的序列整成没有空格的字符串，方便处理。
    chtree.setroot(chtree.build_CBST(str1));
    // chtree.levelorder(chtree.getroot())
    // chtree.setroot(chtree.build_MPT(str1, str2));
    chtree.levelorder(chtree.getroot());
    system("pause");
    return 0;
}
