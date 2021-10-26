#include "lmyllist.h"
#include <iostream>
#include "myllist.h"
#include <cstring>

using namespace std;

int main()
{
	string str; 
	cin >> str;
	lmyllist<char> ch_llarray;
	for (int i=0; i<str.size(); i++)
	{
		ch_llarray.append(str[i]);
	}
	int num_number=0, num_letter=0, num_others=0;
	for (int i=0; i<ch_llarray.length(); i++)
	{
		if (ch_llarray.getvalue()>='0'&&ch_llarray.getvalue()<='9')
		{
			num_number++;
			ch_llarray.erase();
			i--;
			ch_llarray.prev();
		}
		else if (ch_llarray.getvalue()>='a'&&ch_llarray.getvalue()<='z'||ch_llarray.getvalue()>='A'&&ch_llarray.getvalue()<='Z')
		{
			num_letter++;
		}
		else
		{
			num_others++;
		}
		if (i!=-1)
		{
			ch_llarray.next();
		}
	}
	cout <<  num_letter << ' ' << num_number << ' ' << num_others << endl;
	ch_llarray.movetostart();
	// ch_llarray.fordisplay();
	for (int i=0; i<ch_llarray.length(); i++)
	{
		cout << ch_llarray.getvalue();
		ch_llarray.next();
	}
	return 0;
}