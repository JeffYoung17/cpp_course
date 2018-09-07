/*
 * 函数指针，是一个函数程序代码存储的起始地址
 * 回调函数的应用
**/
#include <iostream>

using namespace std;

int compute(int a, int b, int(*pFunc)(int x, int y))
{
    return pFunc(a, b);
}

int sum(int s1, int s2)
{
    return s1+s2;
}

int max(int m1, int m2)
{
    return ( m1>m2?m1:m2 );
}

int min(int m1, int m2)
{
    return ( m1<m2?m1:m2 );
}

int main(int argc, char** argv)
{
    auto result = compute(1, 2, &max); //这种更清晰一点
    //auto result = compute(1, 2, max);这个也是ok的，函数名也代表函数的起始地址
    cout << result << endl;
    return 0;
}