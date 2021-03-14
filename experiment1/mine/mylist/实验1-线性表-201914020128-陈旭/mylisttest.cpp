#include "Amylist.h"
#include <iostream>
#include "mylist.h"
#include <cstring>

using namespace std;

int main()
{
	string str;
	cin >> str;
	Amylist<char> ch_array;
	for (int i=0; i<str.size(); i++)
	{
		ch_array.append(str[i]);
	}
	int num_number=0, num_letter=0, num_others=0;
	for (int i=0; i<ch_array.length(); i++)
	{
		if (ch_array.getvalue()>='0'&&ch_array.getvalue()<='9')
		{
			num_number++;
			ch_array.erase();
			i--;
			ch_array.prev();
		}
		else if (ch_array.getvalue()>='a'&&ch_array.getvalue()<='z'||ch_array.getvalue()>='A'&&ch_array.getvalue()<='Z')
		{
			num_letter++;
		}
		else
		{
			num_others++;
		}
		if (i!=-1)
		{
			ch_array.next();
		}
	}
	cout <<  num_letter << ' ' << num_number << ' ' << num_others << endl;
	ch_array.movetostart();
	// ch_llarray.fordisplay();
	for (int i=0; i<ch_array.length(); i++)
	{
		cout << ch_array.getvalue();
		if (i==ch_array.length()-1)
		{
			break;
		}
		ch_array.next();
	}
	return 0;
}