#ifndef MYLINKBITREE
#define MYLINKBITREE

#include "mybitreenode.h"
#include <cstring>

using namespace std;

template <typename E> class mylinkbitree
{
    private:
        void operator =(const mylinkbitree&) {}    // Protect assignment
        mylinkbitree(const mylinkbitree&) {}
    public:
        mylinkbitree() {};
        virtual node<E>* getroot() const = 0 ;
        virtual void setroot(node<E>* it) = 0;
        virtual bool isempty(node<E>* it) = 0;
        virtual void preorder ()= 0;
        virtual void midorder (node<E>* it) = 0;
        virtual void postorder (node<E>* it) = 0;
        virtual void levelorder (node<E>* it) = 0;
        virtual int depth (node<E>* it) = 0;
        virtual int count (node<E>* it) = 0;
        virtual node<char>* build(string midorder, string postorder) = 0;
        virtual node<char>* createbitree(char ch, string str, int size=0) = 0;
};

#endif
