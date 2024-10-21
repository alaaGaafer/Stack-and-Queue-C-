#ifndef STACKSLL_H_INCLUDED
#define STACKSLL_H_INCLUDED
#include <iostream>
using namespace std;
template<class T>
class StackSLL
{
    SLL<T> S;
public:
    void push(T elem)
    {
        S.addtoHead(elem);
    }
     void pop()
     {
         S.removeFromHead();
     }
      T top()
      {
          return  S.getValueAtHead();
      }
      bool isEmpty()
      {
          return S.isEmpty();
      }
        void clear()
        {
            S.clear();
        }


};


#endif // STACKSLL_H_INCLUDED
