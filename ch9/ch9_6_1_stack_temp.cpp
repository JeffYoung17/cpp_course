/*
 * 实现一个简单的栈的类模板，能够做一些栈的基本操作；
**/
#include <iostream>
#include <cassert>

using namespace std;

template <class T, int SIZE = 50>
class Stack {
private:
    T list[SIZE];
    int top;
public:
    Stack();
    void push(const T& item);
    // 弹出栈，最后栈顶指针要减一
    T pop();
    // 读取栈顶的元素，最后栈顶指针不用减一
    const T& peek() const;
    bool isEmpty() const;
    bool isFull() const;
    void clear();
};

int main(int argc, char** argv)
{

    return 0;
}

template <class T, int SIZE>
Stack<T, SIZE>::Stack():top(-1) {}

template <class T, int SIZE>
void Stack<T, SIZE>::push(const T& item)
{
    assert(!isFull);
    list[++top] = item;
}

template <class T, int SIZE>
T Stack<T, SIZE>::pop()
{
    assert(!isEmpty);
    return list[top--];
}

template <class T, int SIZE>
const T& Stack<T, SIZE>::peek() const
{
    return list[top];
}

template <class T, int SIZE>
bool Stack<T, SIZE>::isEmpty() const
{
    return top == -1;
}

template <class T, int SIZE>
bool Stack<T, SIZE>::isFull() const
{
    return top == SIZE - 1;
}

template <class T, int SIZE>
void Stack<T, SIZE>::clear()
{
    top = -1;
}