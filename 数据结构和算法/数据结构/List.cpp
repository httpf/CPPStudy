/*

*/
#include <iostream>
#include <stdlib.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val = 0, Node *p = NULL)
    {
        data = val;
        next = p;
    }
};

class List
{
private:
    Node *head, *tail;
    int position;
public:
    List()
    {
        head = tail = NULL;
    }
    ~List()
    {
        delete head;
        delete tail;
    }

    void print();

    void Insert(int da = 0);

    void Delete(int da = 0);

    void Search(int da = 0);

    int getValueAt(int position);

    void setValueAt(int position, int da);
};

int List::getValueAt(int position)
{
    Node *p = head;
    if(p == NULL)
    {
        cout << "Empty List!" << endl;
        return;
    }
    else
    {
        int posi = 0;
        while (p != NULL && posi != position)
        {
            posi++;
            p = p->next;
        }
        
        if(p == NULL)
        {
            cout << "This isn't such an position!" << endl;
        }
        else
        {
            cout << "In this position, the value is " << p->data << endl;
        }
    }

    return p->data;
}

void List::setValueAt(int position, int da)
{
    Node *p = head;
    if(p == NULL)
    {
        cout << "Empty List!" << endl;
        return;
    }
    else
    {
        int posi = 0;
        while (p != NULL && posi != position)
        {
            posi++;
            p = p->next;
        }
        
        if(p == NULL)
        {
            cout << "This isn't such an position!" << endl;
        }
        else
        {
            p->data = da;
            cout << "The value of this position has been updated!" << endl;
        }
    }
}

void List::Search(int da)
{
    Node *p = head;
    if(p == NULL)
    {
        cout << "Empty List!" << endl;
        return;
    }
    else
    {
        int count = 0;
        while (p != NULL)
        {
            if(p ->data == da)
            {
                cout << "The position of the value is " << count << endl;
            }
            count++;
            p = p->next;
        }
        if(p == NULL)
        {
            cout << "The list doesn't contain the value." << endl;
        }
    }
}

void List::Delete(int val)
{
    Node *p = head, *q = head;
    if(p == NULL)
    {
        cout << "Empty List!" << endl;
        return;
    }
    while (p != NULL && p->data != val)
    {
        q = p;
        p = p->next;
    }
    if(p == NULL)
    {
        cout << "The list doesn't contail the value." << endl;
        return;
    }
    q->next = p->next;
    delete p;
}

void List::Insert(int da)
{
    if(head == NULL)
    {
        head = tail = new Node(da);
    }
    else
    {
        Node *p = new Node(da);
        tail->next = p;
        tail = p;
    }
}

void List::print()
{
    if(head == NULL)
    {
        cout << "Empty list, do not print." << endl;
        return;
    }
    Node *p = head;
    while(p != NULL)
    {
        cout << p->data << " " << endl;
        p = p->next;
    }
    cout << endl;
}

