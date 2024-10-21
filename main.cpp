#include <iostream>                                                //sg2-alaa usama mohamed shawky-20207013
#include "SLL.h"
#include "StackSLL.h"
#include "QueueSLL.h"
#include<string>
#include <math.h>
using namespace std;
//to check if the parentheses are the same type
bool Balanced(char left, char right)
{
    if (left == '(' && right == ')')
        return true;
    else if (left == '{' && right == '}')
        return true;
    else if (left == '[' && right == ']')
        return true;
    else if (left == '<' && right == '>')
        return true;
    return false;
}
/*checks if the parentheses of an expression are balanced */
bool chkBalanced(string exp)
{
    StackSLL<char>  S;
    int length = exp.length();
    for (int i = 0; i < length; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[' || exp[i] == '<' )     //if it's a left bracket push it
            S.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']' || exp[i] == '>')     //if it's a right bracket
        {
            if (S.isEmpty() || !Balanced(S.top(), exp[i]))                   //and the stack is empty or they are not the same brackets return false
                return false;
            else
                S.pop();
        }
    }
    if (S.isEmpty())                                               //is the stack is empty they are balanced
        return true;
}
/*converts decimal numbers to binary by using a stack*/
string convertToBinary(int num)
{
    string binary_num;
    int temp;
    StackSLL<int>  S;
    if (num==0)
    {
        binary_num='0';
    }
    while (num!=0)
    {
        if(num<0)
        {
            num=num*-1;                      //if the number is negative convert it to positive and put minus sign in binary_num
            binary_num='-';
        }
        S.push(num%2);                    //push the reminder to the stack
        num=num/2;                        //divide number by two
    }
    while(!S.isEmpty())
    {
        temp=S.top();
        S.pop();
        binary_num = binary_num + to_string(temp);           //converting the integers in the stack to strings
    }
    return binary_num;
}
/* to check the priority of the operators and use it in convertInfixToPostfix function */
int priority(char operatorr)
{

    if (operatorr == '^')
        return 3;
    else if (operatorr == '/' || operatorr == '*')
        return 2;
    else if (operatorr == '+' || operatorr == '-')
        return 1;
    else
        return -1;
}
/*converts infix maths expressions to postfix expressions by using a stack*/
string convertInfixToPostfix(string exp)
{
    StackSLL<char>  S;
    string postfix;
    for(int i=0 ; i< exp.length(); i++)
    {
        //if the character is a number put it in the postfix variable
        if(exp[i]>='0' &&exp[i]<='9' )
        {
            postfix=postfix+" "+exp[i];

        }
        //if it's a left bracket push it
        else if(exp[i]=='(')
        {
            S.push(exp[i]);
        }
        //if it's a right bracket pop all what is in the bracket and the left bracket
        else if(exp[i]==')')
        {
            while(S.top()!='(')             //a while loop to pop the contents of the bracket
            {
                postfix=postfix+" "+S.top();
                S.pop();
            }
            S.pop();                 //pops the left bracket
        }
        else if(exp[i]=='^' || exp[i]=='*' || exp[i]=='/' || exp[i]=='+' || exp[i]=='-' )
        {
            while(!S.isEmpty() && priority(S.top())>=priority(exp[i])) //as long as the stack isn't empty and the operator in the stack has higher priority than the one in the epression
            {
                postfix=postfix+" "+S.top();         //put the operator in the stack(higher priority) in the postfix variable
                S.pop();                            //remove it from the stack
            }
            S.push(exp[i]);                         //push the operator with the lower priority (exp[i])
        }
    }
    while(!S.isEmpty())           //put all of the operators in the stack in the postfix variable
    {
        postfix=postfix +" "+S.top();
        S.pop();
    }
    return postfix;
}
/*calculates the result of a maths postfix expression made by the previous function */
int evaluatePostfix(string exp)
{
    int a=0,b=0, res=0;
    int n;
    StackSLL<int> s1;
    for(int i=0 ; i< exp.length(); i++)
    {
        if((exp[i]>='0' &&exp[i]<='9') )         //if the character is a number
        {
            n=exp[i]-'0';                        //turn it into an integer by subtracting '0'(48)
            s1.push(n);                          //push the integer into the stack
        }
        else if(exp[i]=='^' || exp[i]=='*' || exp[i]=='/' || exp[i]=='+' || exp[i]=='-' ) //if it's an operator
        {
            if(exp[i]=='*')
            {
                a= s1.top();                    //put the top element in a
                s1.pop();
                b=s1.top();                     //put the second top element in b
                s1.pop();
                s1.push(a*b);                  //perform the operation and push the result back to the stack
            }

            else if(exp[i]=='/')
            {
                b=s1.top();
                s1.pop();
                a=s1.top();
                s1.pop();
                s1.push(a/b);
            }

            else if(exp[i]=='+')
            {
                b=s1.top();
                s1.pop();
                a=s1.top();
                s1.pop();
                s1.push(a+b);
            }

            else if(exp[i]=='-')
            {
                b=s1.top();
                s1.pop();
                a=s1.top();
                s1.pop();
                s1.push(a-b);
            }

            else if(exp[i]=='^')
            {
                b=s1.top();
                s1.pop();
                a=s1.top();
                s1.pop();
                res=(int)(pow(a, b)+1e-9);
                s1.push(res);
            }

        }
    }
    res=s1.top();           //storing the final value in res and returning it
    s1.pop();
    return res;
}
/*moves the nth element to the head of the queue using two queues*/
template<class T>
bool moveNthElem(QueueSLL<T>& Q,int n)
{
    QueueSLL<T> Q2;
    int i=0;
    T elem;
    bool inrange=false;      //boolean variable to check if n in the range of the queue
    while(!Q.isEmpty())
    {
        if (i==n-1)          //if the front element is the nth element wanted to be moved
        {
            elem=Q.front();                //store it in a variable and remove it from the queueue
            Q.dequeue();
            inrange=true;                  //n is in range of the queue
        }
        else
        {
            Q2.enqueue(Q.front());       //else store the front element of Q in Q2 and remove it from Q
            Q.dequeue();
        }
        i++;
    }
    if(inrange==false)
    {
        cout<<"the position isn't in range of the queue,go back to the menu and try again"<<endl;
        return inrange;
    }
    Q.enqueue(elem);                               //put the nth element in the front of the parameter queue
    while(!Q2.isEmpty())                           //then enqueue the other elements
    {
        Q.enqueue(Q2.front());
        Q2.dequeue();
    }
    cout<<"the new queue : ";
    while(!Q.isEmpty())                          //displaying the queue
    {
        cout<<Q.front()<<" ";
        Q.dequeue();
    }
    cout<<endl;
    return true;
}
/*reverses a queue by using a stack */
template<class T>
void reverseQueue(QueueSLL<T>& Q)
{
    StackSLL<T> s;
    while(!Q.isEmpty())
    {
        s.push(Q.front());
        Q.dequeue();
    }
    cout<<"The reversed queue is : ";
    while(!s.isEmpty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
void menu()
{
    cout<<"1- Check for balanced brackets."<<endl;
    cout<<"2-Convert to binary"<<endl;
    cout<<"3-Convert infix to postfix expression and evaluate."<<endl;
    cout<<"4- Move Nth element to front in a queue of strings"<<endl;
    cout<<"5-Reverse elements of a queue of doubles."<<endl;
    cout<<"6-Exit"<<endl;
}
int main()
{
    int choice;
    menu();                               //calling the menu
    do
    {
        cout<<"enter your choice: ";
        cin>>choice;
        /*************chkBalanced*************/
        if (choice==1)
        {
            string exp;
            cout<<"enter an expression "<<endl;
            cin.ignore();
            getline(cin, exp);
            if (chkBalanced(exp))
            {
                cout<<"Balanced"<<endl;
            }
            else
            {
                cout<<"Imbalanced"<<endl;
            }
        }
        /*************convertToBinary*************/
        else if (choice==2)
        {
            int num=0;
            cout<<"enter a number" <<endl;
            cin>>num;
            cout<<num<<" in binary is: "<<convertToBinary(num)<<endl;
        }
        /*************convertInfixToPostfix*************/
        else if (choice==3)
        {
            string exp;
            cout<<"enter an expression"<<endl;
            cin.ignore();
            getline(cin, exp);
            exp=convertInfixToPostfix(exp);
            cout<<"the postfix notation is: "<<exp<<endl;
            cout<<"the evaluation of the expression is: "<<evaluatePostfix(exp)<<endl;

        }
        /*************moveNthElem*************/
        else if (choice==4)
        {
            QueueSLL<string> Q;
            string exp;
            char Continue;
            do
            {
                cout<<"enter an element "<<endl;
                cin.ignore();
                getline(cin, exp);
                Q.enqueue(exp);
                cout<<"do you want to enter another element ? y/n "<<endl;
                cin>>Continue;
                while((Continue != 'y') && (Continue != 'n') && (Continue != 'Y') && (Continue != 'N'))
                {
                    cout<<"invalid entry,please enter y/n"<<endl;
                    cin>>Continue;
                }
            }
            while((Continue != 'n') && (Continue!='N'));
            cout<<"enter the position of the element you want to move to the front of the queue "<<endl;
            int num;
            cin>>num;
            while(num<=0)
            {
                cout<<"the position can't be 0 or less,please enter a positive number "<<endl;
                cin>>num;
            }
            moveNthElem(Q,num);
        }
        /*************reverseQueue*************/
        else if (choice==5)
        {
            QueueSLL<double> Q;
            double elem;
            char Continue;
            do
            {
                cout<<"enter an element "<<endl;
                cin>>elem;
                Q.enqueue(elem);
                cout<<"do you want to enter another element ? y/n "<<endl;
                cin>>Continue;
                while((Continue != 'y') && (Continue != 'n') && (Continue != 'Y') && (Continue != 'N'))
                {
                    cout<<"invalid entry,please enter y/n"<<endl;
                    cin>>Continue;
                }
            }
            while((Continue != 'n') && (Continue!='N'));
            reverseQueue(Q);
        }
        else
        {
            cout<<"invalid entry,please enter a number from 1 to 6"<<endl;
        }
    }
    while(choice!=6);
    return 0;
}
