/**
 * 函数指针
 */
#include <iostream>
#include <cmath>

using namespace std;

int compute(int a, int b, int (*pFunc)(int, int))
{
    return (*pFunc)(a, b);
}

int min(int a, int b)
{
    return (a < b ? a : b);
}

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int a = 1, b = 2;
    cout << compute(a, b, &min) << endl;
    cout << compute(a, b, &add) << endl;
    return 0;
}