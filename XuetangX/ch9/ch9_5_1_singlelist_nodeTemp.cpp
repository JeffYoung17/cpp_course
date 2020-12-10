/*
 * 实现一个简单的结点的类模板；
**/
#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class Node {
private:
    Node<T>* next;
public:
    T data;
    // 构造函数
    Node(const T& item, Node<T>* nextPtr = NULL);
    // 在当前结点后面插入一个结点
    void insertAfter(Node<T>* ptr);
    // 删除当前结点的下一个结点,返回要删除结点的指针，释放动态内存空间或者有别的用途
    Node<T>* deleteAfter();
    // 返回当前结点的下一个结点的指针
    Node<T>* nextNode() const;
};

int main(int argc, char** argv)
{

    return 0;
}

template <class T>
Node<T>::Node(const T& item, Node<T>* nextPtr) : data(item), next(nextPtr) {}

template <class T>
void Node<T>::insertAfter(Node<T>* ptr)
{
    ptr->next = next;
    next = ptr;
}

template <class T>
Node<T>* Node<T>::deleteAfter()
{
    Node<T>* tempPtr = next;
    if(next == NULL)
        return 0;
    next = tempPtr->next;
    return tempPtr;
}

template <class T>
Node<T>* Node<T>::nextNode() const
{
    return next;
}