/*
以下代码是基于list实现的队列
*/

#include <iostream>
#include <list>

using namespace std;

template<class T>
class Queue
{
public:
    Queue() = default;
    bool isEmpty() const;
    T& front();
    T dequeue();
    void enqueue(const T&);
    size_t size() const;
    void clear();
private:
    list<T> lst;
};

template<class T>
bool Queue<T>::isEmpty() const
{
    return lst.empty();
}

template<class T>
T& Queue<T>::front()
{
    lst.front();
}

template<class T>
T Queue<T>::dequeue()
{
    if(!lst.size())
    {
        cout << "Queue Empty." << endl;
        return NULL;
    }
    T tmp = lst.front();
    lst.pop_front();
    return tmp;
}

template<class T>
void Queue<T>::enqueue(const T& elem)
{
    lst.push_back(elem);
}

template<class T>
size_t Queue<T>::size() const
{
    return lst.size();
}

template<class T>
void Queue<T>::clear()
{
    lst.clear();
}