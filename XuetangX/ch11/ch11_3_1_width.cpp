/*
 * 设置字符输出的宽度
 * 默认方式采用右对齐
 * cout对象的width()成员函数和操纵符setw
**/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main( int argc, char** argv )
{
    double values[] = { 1.23, 35.36, 643.9, 3492.92 };
    for( int i=0; i<4; i++)
    {
        cout.width(10);
        cout << values[i] << endl;
    }

    string names[] = { "mike", "mary", "stark", "jeff" };
    for( int i=0; i<4; i++ )
    {
        cout << setw(6) << names[i] << setw(10) << values[i] << endl;
    }

    for( int i=0; i<4; i++ )
    {
        cout << setiosflags(ios_base::left)
            << setw(6) << names[i]
            << resetiosflags(ios_base::left)
            << setw(10) << values[i] << endl;
    }

    return 0;
}