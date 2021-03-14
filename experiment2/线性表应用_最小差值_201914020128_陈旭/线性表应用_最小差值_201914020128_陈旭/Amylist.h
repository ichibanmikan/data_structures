//array based list
//顺序表的实现
#include "mylist.h"
#include <assert.h>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename E>
class Amylist : public mylist<E>
{
    private:
        int maxsize; //线性表总长度
        int listsize; //线性表中元素个数
        int curr; //当前元素值
        E* array; //E类型数组，即存储线性表元素的数组
    public:
        Amylist (int size=100)
        {
            maxsize=100;
            listsize=0;
            curr=0;
            array = new E[maxsize];
        } //构造函数
        ~Amylist ()
        {
            delete [] array;
        } //析构函数
        int length() const
        {
            return listsize;
        }
        void insert(const E& it)
        {
            assert(listsize<maxsize);
            for (int i=curr; i<listsize; i++)
            {
                array[i+1]=array[i];
            }
            listsize++;
            array[curr]=it;
        }
        void clear()
        {
            // for (int i=0; i<listsize; i++)
            // {

            // }
            delete [] array;
            curr=0;
            listsize=0;
            array=new E[maxsize];
        }
        void append(const E& it)
        {
            assert(listsize<maxsize);
            array[listsize]=it;
            listsize++;
        }
        E erase()
        {
            E& item=array[curr];
            for (int i=curr+1; i<listsize; i++)
            {
                array[i-1]=array[i];
            }
            listsize--;
            return item;
        }
        E poserase(int &pos)
        {
            int &temp=curr;
            curr=pos;
            erase();
            curr=temp;
        }
        bool erasex(E &x)
        {
            if (listsize<=0) return false;
            else
            {
                E* temparray;
                int temp=0;
                for (int i=0; i<listsize; i++)
                {
                    if (array[i]==x)
                     {
                        temparray[temp]=i;
                        temp++;
                     }
                }
                for (int j=0; j<temp; j++)
                {
                    if (j==temp-1)
                    {
                        for (int i=temparray[j]+1; i<listsize; i++)
                        {
                            array[i-temp]=array[i];
                            listsize--;
                        }
                    }
                    else
                    {
                        for(int i=temparray[j]+1; i<temparray[j+1]; i++)
                        {
                            array[i-j]=array[i];
                            listsize--;
                        }
                    }
                }
                delete [] temparray;
                return true;
            } 
        }
        void next()
        {
            assert(curr<listsize);
            curr++;
        }
        void movetostart()
        {
            curr=0;
        }
        void movetoend()
        {
            curr=listsize;
        }
        void prev()
        {
            if (curr==0) 
            {
                return ;
            }
            curr--;
        }
        int currpos()
        {
            return curr;
        }
        void setpos(int &pos)
        {
            assert(pos<=listsize);
            curr=pos;
        }
        const E& getvalue()
        {
            assert((curr>=0)&&(curr<=listsize));
            return array[curr];
        }
        void fordisplay()
        {
            for (int i=0; i<listsize; i++)
            {
                cout << array[i] << ' ';
            }
            cout << endl;
        }
        void setorder()
        {
            sort(array, array+listsize);
        }
};
