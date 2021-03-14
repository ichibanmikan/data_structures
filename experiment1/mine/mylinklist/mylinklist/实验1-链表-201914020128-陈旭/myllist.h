#ifndef MYLLIST
#define MYLLIST

template <typename E> class myllist
{
    private:
        void operator =(const myllist&) {}      // Protect assignment
        myllist(const myllist&) {}           // Protect copy constructor
    public:
        myllist () {}; //���캯��
        virtual ~myllist() {}; //��������
        virtual void next() = 0;
        virtual int length() const = 0; //���ص�ǰ���Ա�Ԫ�صĸ���
        virtual void insert(const E& it) = 0; //�ڵ�ǰλ�ò���һ��Ԫ��
        virtual void clear () = 0; //������Ա��е�����?1�?7
        virtual void append (const E& it) = 0; //β��һ��Ԫ��
        virtual E erase () = 0; //ɾ�����Ա��е�ǰԪ�ز�������Ϊ����ֵ
        // virtual E poserase (int& pos) = 0; //ɾ�����Ա���ָ��λ��Ԫ��
        virtual void movetostart () = 0; //����ǰλ���ƶ������Ա���ͷ
        virtual void movetoend () = 0; //����ǰλ���ƶ������Ա�ĩβ
        virtual void prev () = 0; //����ǰλ�������ƶ�һλ
        virtual int currpos () = 0; //���ص�ǰλ��
        virtual void setpos(int &pos) = 0;//��ָ��λ������Ϊ��ǰλ��
        virtual const E& getvalue() = 0; //���ص�ǰԪ��ֵ
        virtual void fordisplay () = 0;//ѭ������������?1�?7�ص�ֵ
        // virtual void setorder() = 0;
};

#endif
