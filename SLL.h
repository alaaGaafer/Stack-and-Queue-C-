#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDE
#include <iostream>
using namespace std;

template<class T>
class Node
{
    T info;
    Node* next;
public:
    Node()
    {
        next=0;
    }
    Node (T elem, Node* n = 0)
    {
        next = elem;
        info = n;
    }
    Node* getNext ()
    {
        return next;
    }
    void setNext(Node* pt)
    {
        next = pt;
    }
    T getInfo ()
    {
        return info;
    }
    void setInfo (T n)
    {
        info = n;
    }
};

template<class T>
class SLL
{
    Node<T> *head, *tail;
public:
    SLL()
    {
        head = tail = 0;
    }
    void addtoHead(T newvalue)
    {
        Node<T>* newnode= new Node<T>();
        newnode->setInfo(newvalue);
        if (isEmpty())
        {
            head =tail =newnode;
        }
        else
        {
            newnode->setNext(head);
            head = newnode;
        }
    }
    void addtoTail(T newvalue)
    {
        Node<T>* newnode= new Node<T>();
        newnode->setInfo(newvalue);
        if (isEmpty())
        {
            head = tail = newnode;
        }
        else
        {
            tail->setNext(newnode);
            tail = newnode;
        }
    }
    T removeFromHead()
    {
        T value;
        if (isEmpty())
        {
            cout<<"the list is empty, there is no items to be deleted"<<endl;
        }
        if (head == tail)
        {
            value=head->getInfo();
            delete head;
            head = tail = 0;
            return value;
        }
        else
        {
            Node<T>* delptr= head;
            head=head->getNext();
            value=delptr->getInfo();
            delete delptr;

            return value;
        }

    }
    T removeFromTail()
    {
        T value;
        if (isEmpty())
        {
            cout<<"the list is empty, there is no items to be deleted"<<endl;
        }
        if (head == tail)
        {
            value=head->getInfo();
            delete head;
            head = tail = 0;

            return value;
        }
        else
        {
            Node<T>* delptr= head;
            while(delptr->getNext()->getNext() != NULL)
            {
                delptr=delptr->getNext();
            }
            tail= delptr;
            delptr=delptr->getNext();
            value=delptr->getInfo();
            delete delptr;

            return value;
        }
    }
    T getValueAtHead()
    {
        return head->getInfo();
    }
    bool isEmpty()
    {
        return head==NULL;
    }
    void clear()
    {
        while(!isEmpty())
        {
            removeFromHead();
        }
        cout<<"list cleared"<<endl;
    }
    template<class n>
    friend ostream& operator<<(ostream&os, const SLL<n>& node);
};
template<class n>
ostream& operator<<(ostream&os, const SLL<n>& node)
    {
        Node<n> *p = node.head;
        while (p != 0)
        {
            os << p->getInfo() << " ";
            p = p->getNext();
        }

        return os;

    }



#endif // SLL_H_INCLUDED
