#pragma once
#include<iostream>
using namespace std;
template<class T>
struct Node
{
    T value;
    Node<T>* next;
    Node<T>* prev;
};
template <class T>
class Cdbll
{
private:
    Node<T>* first;
    Node<T>* last;
    int count;
protected:
    void destroy();
    void copylist(const Cdbll<T> &otherlist);
    int counterlist();
public:
    Cdbll();
    ~Cdbll();
    Cdbll(const Cdbll<T>& otherlist);
    void operator=(const Cdbll<T>& otherlist);
    void insertFront(const T& item);
    void insertEnd(const T& item);
    void print();
    int length();
    void deleteItem(const T& item);
    void emptylist();
    bool searchItem( T item);
    bool isEmpty();
    void iterateFront();
    void iterateBack();
};