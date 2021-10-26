#include <iostream>
#include "mybitree.h"
#include "mybitreenode.h"
#include "realisemybitreenode.h"
#include <queue>
#include <stack>

using namespace std;

template <typename E>
class realisemylinkbitree : public mylinkbitree <E>{
    private:
        node<E>* root;
    public:
        node<E>* getroot() const{
            return root;
        }
        void setroot (node<E>* it){
            root=it;
        }
        bool isempty(node<E>* it){
            if (it->lc==NULL&&it->rc==NULL){
                return true;
            }
            else{
                return false;
            }
        }
        void preorder(node<E>* it){
            if (it!=NULL){
                cout << it->element << ' ';
                preorder(it->lc);
                preorder(it->rc);
            }
//            cout << endl;
        }
        void midorder(node<E>* it){
            if (it!=NULL){
                midorder(it->lc);
                cout << it->element << ' ';
                midorder(it->rc);
            }
//            cout << endl;
        }
        void postorder(node<E>* it){
            if (it!=NULL){
                postorder(it->lc);
                postorder(it->rc);
                cout << it->element << ' ';
            }
//            cout << endl;
        }

        void preorder() {
            postorder(root);
            cout<<endl;
        }

        void levelorder(node<E>* it){
            queue<node<E>*> q;
            if(it!=NULL){
                q.push(it);
            }
            node<E>* b;
            while(!q.empty()){
                b=q.front();
                cout<<b->element<<' ';
                q.pop();
                if(b->left()){
                    q.push(b->left());
                }
                if(b->right()){
                    q.push(b->right());
                }
            }
        }
        int depth(node<E>* it){
            int lh=0,rh=0 ;
            if(it!=NULL){
                lh=depth(it->left());
                rh=depth(it->right());
                return (lh>rh?lh:rh)+1;
            }
            else {
                return 0;
            }
        }
        int count(node<E>* it){
            if(it!=NULL) {
                return count(it->left())+count(it->right())+1;
            }
            else {
                return 0;
            }
        }
        node<char>* build(string midorder, string postorder) {
            node<char>* it;
            char _root = postorder.at(postorder.length() - 1);
            int position = midorder.find(_root);
            int leftsize = position;
            int rightsize = midorder.length() - position - 1;
            it = new realisemybitreenode<char>;
            it->setelement(_root);
            it->setleft(leftsize ? build(midorder.substr(0, leftsize), postorder.substr(0, leftsize)) : NULL);
            it->setright(rightsize ? build(midorder.substr(position + 1, rightsize), postorder.substr(leftsize, rightsize)) : NULL);
            return it;
        }
        node<char>* createbitree(char ch, string str, int size=0){
            node<char>* it;
            if (ch=='#'){
                it = NULL;
            }
            else{
                it = new realisemybitreenode<char>; /**/
                it->setelement(ch);
                ch=str[++size];
                it->setleft(createbitree(ch, str, size));
                ch=str[++size];
                it->setright(createbitree(ch, str, size));
            }
            setroot(it);
            return it;
        }
};
