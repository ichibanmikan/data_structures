#include <iostream> 

template <typename E> class link 
{
  public:
    E element;      // ????
    link *next;        // ??????
    link(const E& elemval, link* nextval =NULL)
    { 
      element = elemval;
      next = nextval; 
    }
    link(link* nextval =NULL) 
    { 
      next = nextval; 
    }
}; //??????????(node)????‰^


