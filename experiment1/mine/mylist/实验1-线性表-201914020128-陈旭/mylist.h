// array based list
//顺序表的声明

#ifndef MYLIST 
#define MYLIST

template <typename E> class mylist
{
    private:
        void operator =(const mylist&) {}      // Protect assignment
        mylist(const mylist&) {}           // Protect copy constructor
    public:
        mylist () {}; //构造函数
        virtual ~mylist() {}; //析构函数
        virtual int length() const = 0; //返回当前线性表元素的个数
        virtual void insert(const E& it) = 0; //在当前位置插入一个元素
        virtual void clear () = 0; //清空线性表中的内容
        virtual void append (const E& it) = 0; //尾插一个元素
        virtual E erase () = 0; //删除线性表中当前元素并将其作为返回值
        virtual E poserase (int& pos) = 0; //删除线性表中指定位置元素
        virtual void next () = 0;//将当前位置向后移动一位
        virtual void movetostart () = 0; //将当前位置移动到线性表开头
        virtual void movetoend () = 0; //将当前位置移动到线性表末尾
        virtual void prev () = 0; //将当前位置向左移动一位
        virtual int currpos () = 0; //返回当前位置
        virtual void setpos(int &pos) = 0;//将指定位置设置为当前位置
        virtual const E& getvalue() = 0; //返回当前元素值
        virtual bool erasex (E &x) = 0; //删除线性表中所有值为x的元素
        virtual void fordisplay () = 0;//循环输出链表中元素的值
        virtual void setorder () = 0;
};

#endif