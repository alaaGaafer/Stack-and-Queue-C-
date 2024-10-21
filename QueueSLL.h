#ifndef QUEUESLL_H_INCLUDED
#define QUEUESLL_H_INCLUDED
#include <iostream>
using namespace std;
template<class T>
class QueueSLL
{
    SLL<T> S;
public:
    void enqueue(T elem)
    {
        S.addtoTail(elem);
    }
    void dequeue()
    {
        S.removeFromHead();
    }
    T front()
    {
        return S.getValueAtHead();
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

#endif // QUEUESLL_H_INCLUDED
