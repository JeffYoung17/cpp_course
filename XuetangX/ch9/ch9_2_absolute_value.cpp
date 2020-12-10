/*
 * 函数模板：求一个数的绝对值
 * 注意语法，当调用abs(pi)，因为pi是double类型，编译器会把函数模板中的参数T换成double
 * 当调用abs(n)，因为n是int类型，编译器会把函数模板中的参数T换成int
**/

#include <iostream>

using namespace std;

template<typename T>
T abs(T x)
{
    return x<0 ? -x:x;
}

int main(int argc, char** argv)
{
    double pi = 3.14;
    int n = -1;
    cout << abs(pi) << endl;
    cout << abs(n) << endl;
    return 0;
}