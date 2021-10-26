#include "mybitreenode.h"

template <typename E> 
class realisemybitreenode : public node<E>
{
    public:
      E& getelement() 
      { 
        return node<E>::element; 
      }
      node<E>* left() 
      { 
        return node<E>::lc;
      }
      node<E>* right() 
      { 
        return node<E>::rc; 
      }
      void setelement(E& it) 
      { 
        node<E>::element=it; 
      }
      void setleft(node<E>* b) 
      { 
        node<E>::lc=b; 
      }
      void setright(node<E>* b) 
      { 
        node<E>::rc=b; 
      }
      bool isleaf() 
      { 
        return (node<E>::lc==NULL)&&(node<E>::rc==NULL); 
      }
};
