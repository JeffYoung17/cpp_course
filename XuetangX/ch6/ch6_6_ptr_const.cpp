/*
 * 指向常量的指针
 * 指针本省是常量
**/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    const double PI = 3.14;
    double speed = 0.8;

    const double* ptr1 = &PI;
    cout << *ptr1 << endl;
    ptr1 = &speed;
    cout << *ptr1 << endl;

    int num = 10;
    int* const ptr2 = &num;
    cout << num << endl;
    *ptr2 = 20;//equal to num=20
    cout << num << endl;

    return 0;
}

