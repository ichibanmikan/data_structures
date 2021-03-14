#include "myllist.h"
#include <assert.h>
#include "link.h"
#include <algorithm>

using namespace std;

template <typename E>
class lmyllist : public myllist<E>
{ 
    private:
         link<E> *head; //ͷָ��
         link<E> *tail; //βָ��
         link<E> *curr; //��ǰָ��
         int cnt; //��ǰ������Ԫ�ظ���
         void removeall ()
         {
             while (head!=NULL)
             {
                 curr=head;
                 head=head->next;
                 delete curr;
             }
         }
         void init()
         {
             tail=head=curr=new link<E>;//���߽�Ϊ������ָ�룬ָ����?�ذ���һ�����ָ���һ����ǰԪ�أ��Լ�������������������ʱʹ��'->';
             cnt=0;
         } 
    public:
        lmyllist(int size=100) { init(); }
        ~lmyllist() { removeall(); }
         void next()
         {
            if (curr!=tail) 
            {
                curr=curr->next;
            }
         }
        int length() const
        {
            return cnt;
        }
        void insert(const E& it)
        {
            if (cnt==0)
            {
                head->next->element=it;
                tail=head->next;
                cnt++;
            }
            else
            {
                cnt++;
                curr->next=new link<E> (it, curr->next); //new�ķ���ֵ�Ƕ���ĵ��?!!! //���������curr->next�ǵ��ù��캯�������±�����ָ��ֱ��ָ����һ��
                if(curr==tail) { tail=curr->next; }
            }
        }
        void clear()
        {
            removeall();
            init();
        }
        void append(const E& it)
        {
        	tail = tail->next = new link<E>(it, NULL);
    		cnt++;
        //    if (cnt==0)
        //    {
        //        head->next->element=it;
        //        curr=curr->next;
        //        tail=head->next;
        //        cnt++;
        //    }
        //    else
        //    {
        //        tail=tail->next=new link<E>(it, NULL);
        //        cnt++;
        //    }
        }
        void fordisplay ()
        {
            assert(cnt > 0);
            link<E> *ltemp; 
            curr=head->next;
            while (curr!=NULL)
            {
            	cout << curr->element << ' ';
                curr=curr->next;
			}
            cout << endl;
            curr=ltemp;
            delete ltemp;
        }//�����ж�������Ԫ���Ƿ��������Դ洢
        E erase()
        {
            assert(curr->next!=NULL);
            E it=curr->next->element;
            link<E> *ltemp=curr->next;
            if (curr->next==tail)
            {
                tail=curr;
            }
            curr->next=curr->next->next;
            cnt--;
            delete ltemp;
            return it;
        }
        void movetostart()
        {
            curr=head;
        }
        void movetoend()
        {
            curr=tail;
        }
        void prev()
        {
            // if (curr == head) return;       // ֮ǰû��Ԫ�� 
            // link<E>* temp = head;
            // // March down list until we find the previous element
            // while (temp->next!=curr) temp=temp->next;
            // curr = temp;
            if (curr==head)
            {
                return;
            }
            link<E> *ltemp=curr;
            curr=head;
            while (curr->next!=ltemp)
            {
                curr=curr->next;
            }
            // delete ltemp;
        }
        int currpos()
        {
            // if (head==tail) return 0;
            int pos=0;
            link<E> *ltemp=head;
            while (ltemp!=curr)
            {
                ltemp=ltemp->next;
                pos++;
            }
            delete ltemp;
            return pos;
        }
        void setpos(int& pos)
        {
            if(pos<0||pos>cnt) return;
            // link<E> *ltemp=head;
            curr=head;
            for (int i=0; i<pos; i++)
            {
                curr=curr->next;
            }
        }
        const E& getvalue ()
        { 
        	assert(curr->next!=NULL);
//            if (curr==tail) return;
            return curr->next->element;
        }
        // void setorder()
        // {
        //     sort(listarray)
        // }
};