/*
如下代码为单链表实现的栈
*/

#include <iostream>

using namespace std;

template <class T>
struct StackNode
{
    T data;
    StackNode *next;
};

template <class T>
class MyStack
{
public:
    MyStack();
    ~MyStack();
    void push(T data);
    void pop();
    T getTop();
    bool isEmpty();
private:
    StackNode<T> *top;
};

template <class T>
MyStack<T>::MyStack()
{
    top = NULL;
}

template <class T>
MyStack<T>::~MyStack() //top指针朝向为由栈顶指向栈底
{
    StackNode<T> *node = NULL;
    while(top != NULL)
    {
        node = top;
        top = top->next;
        delete top;
    }
}

template <class T>
void MyStack<T>::push(T data)
{
    StackNode<T> *p = new StackNode<T>;
    p->data = data;
    p->next=top;
    top = p;
}

template <class T>
void MyStack<T>::pop()
{
    if(top == NULL)
    {
        cout << "Empty stack, can't pop()!" << endl;
        return;
    }
    StackNode<T> *p = top;
    top = top->next;
    delete p;
}

template <class T>
T MyStack<T>::getTop()
{
    return top->data;
}

template <class T>
bool MyStack<T>::isEmpty()
{
    if(top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}