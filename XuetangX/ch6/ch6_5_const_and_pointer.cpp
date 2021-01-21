/**
 * 指向常量的指针
 * 常指针
 */
#include <iostream>

using namespace std;

int main()
{
    // pointer to const
    int a = 1;
    const int* ptr2const = &a;
    cout << "addr of a: " << ptr2const << endl;
    int b = 2;
    // *ptr2const = 3; // 错误的操作
    ptr2const = &b;
    cout << "addr of b: " << ptr2const << endl;

    // const pointer
    int c = 1;
    int* const constPtr = &c;
    cout << "addr of c: " << constPtr << endl;
    cout << "c is: " << c << endl;
    int d = 8;
    // constPtr = &d; // 错误的操作
    *constPtr = 7;
    cout << "new c: " << c << endl;
    return 0;
}