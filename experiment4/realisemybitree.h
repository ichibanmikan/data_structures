#include <iostream>
#include "mybitree.h"
#include "mybitreenode.h"
#include "realisemybitreenode.h"
#include <queue>
#include <cmath>

using namespace std;

template <typename E>
class realisemylinkbitree : public mylinkbitree <E>
{
    private:
        node<E>* root;
    public:
        node<E>* getroot() const
        {
            return root;
        }
        void setroot (node<E>* it)
        {
            root=it;
        }
        bool isempty(node<E>* it)
        {
            if (it->lc==NULL&&it->rc==NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void preorder(node<E>* it)
        {
            if (it!=NULL)
            {
                cout << it->element << ' ';
                preorder(it->lc);
                preorder(it->rc);
            }
//            cout << endl;
        }
        void midorder(node<E>* it)
        {
            if (it!=NULL)
            {
                midorder(it->lc);
                cout << it->element << ' '; //出错位置
                midorder(it->rc);
            }
//            cout << endl;
        }
        void postorder(node<E>* it)
        {
            if (it!=NULL)
            {
                postorder(it->lc);
                postorder(it->rc);
                cout << it->element << ' ';
            }
//            cout << endl;
        }

        void preorder() 
		{
            postorder(root);
            cout<<endl;
        }

        void levelorder(node<E>* it)
        {
            queue<node<E>*> q;
            if(it!=NULL)
            {
                q.push(it);
            }
            node<E>* b;
            while(!q.empty())
            {
                b=q.front();
                cout<<b->element<<' ';
                q.pop();
                if(b->left())
                {
                    q.push(b->left());
                }
                if(b->right())
                {
                    q.push(b->right());
                }
            }
        }
        int depth(node<E>* it)
        {
            int lh=0,rh=0 ;
            if(it!=NULL)
            {
                lh=depth(it->left());
                rh=depth(it->right());
                return (lh>rh?lh:rh)+1;
            }
            else 
            {
                return 0;
            }
        }
        int count(node<E>* it)
        {
            if(it!=NULL)  
            {
                return count(it->left())+count(it->right())+1;
            }
            else 
            {
                return 0;
            }
        }
        node<char>* build_MPT(string postorder, string midorder) 
        {
            node<char>* it;
            char _root = postorder.at(postorder.length() - 1);
            int position = midorder.find(_root);
            int leftsize = position;
            int rightsize = midorder.length() - position - 1;
            it = new realisemybitreenode<char>;
            it->setelement(_root);
            it->setleft(leftsize ? build_MPT(postorder.substr(0, leftsize), midorder.substr(0, leftsize)) : NULL);
            it->setright(rightsize ? build_MPT( postorder.substr(leftsize, rightsize), midorder.substr(position + 1, rightsize)) : NULL);
            return it;
        }
        node<char>* build_MPR(string preorder, string midorder)
        {
            node <char>* it;
            char _root=preorder.at(0);
            int position=midorder.find(_root);
            it = new realisemybitreenode<char>;
            it->setelement(_root);
            it->setleft(preorder.size()!=1 ? build_MPR(preorder.substr(1, position), midorder.substr(0, position)) : NULL);
            it->setright(preorder.size()!=1 ? build_MPR(preorder.substr(position+1, preorder.size()-position-1), midorder.substr(position+1, midorder.size()-position-1)) : NULL);
            return it;
        }
        int getFloor(int num)
        {
            return log(num)/log(2);
        }//返回二叉树的层数(深度，最长路径)
        int leftNodeCount(int num)
        {
            int leafNode=num-pow(2, getFloor(num))+1;
            int midNode=pow(2, getFloor(num)-1);
            leafNode=midNode>leafNode?leafNode:midNode;
            return leafNode+midNode-1;
        }//返回需要插入的左子树的节点个数
        int rightNodeCount(int num)
        {
            return num-1-leftNodeCount(num);
        }//返回需要插入的左子树的节点个数
        node<char>* build_CBST(string upperOrder)
        {
        	string ss=upperOrder;
            node<char>* it;
            int leftNodenum=leftNodeCount(upperOrder.size());
            int rightNodenum=rightNodeCount(upperOrder.size());
            it=new realisemybitreenode<char>;
            it->setelement(upperOrder[leftNodenum]);
            cout << "   " << upperOrder << endl;
            it->setleft(/*leftNodenum!=1*/ss.size()!=1?build_CBST(ss.substr(0, leftNodenum)):NULL);
            it->setright(/*leftNodenum!=1*/upperOrder.size()!=1?build_CBST(upperOrder.substr(leftNodenum+1, rightNodenum)):NULL);
            return it;
        }//建树的过程
};
