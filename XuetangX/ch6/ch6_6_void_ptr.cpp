#include <iostream>

using namespace std;

int main()
{
    int i = 2;
    // 指向void类型的指针变量, 只能用来存放地址, 不能用它来访问其所指向的内存空间
    void* ptr; 
    ptr = &i;
    // cout << *ptr << endl; // 错误的方法
    int* intPtr = static_cast<int*>(ptr);
    cout << *intPtr << endl;
    double x = 1.1;
    ptr = &x;
    double* dbPtr = static_cast<double*>(ptr);
    cout << *dbPtr << endl;
    return 0;
}