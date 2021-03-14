#ifndef NODE
#define NODE

template <typename E> class node
{
    public:
      E element;
      node<E>* lc;
      node<E>* rc;
      node (E &elemval, node<E>* l, node<E>* r)
      { 
        element=elemval;
        lc=l;
        rc=r;
      }
      node ()
      {
        lc=rc=NULL;
      }
      virtual E& getelement () = 0;
      virtual node<E>* left() = 0;
      virtual node<E>* right() = 0;
      virtual void setelement(E& it) = 0;
      virtual void setleft(node<E>* b) = 0;
      virtual void setright(node<E>* b) = 0;
      virtual bool isleaf() = 0;
};

#endif 