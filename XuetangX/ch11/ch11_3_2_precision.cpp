/*
 * 设置输出的精度
 * 不指定的话，系统会根据数字的特点自动输出
 * 设置setiosflags操纵符以后，输出完以后最好有resetiosflags的习惯
**/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main( int argc, char** argv )
{
    double values[] = { 1.23, 35.36, 643.9, 3492.92 };
    string names[] = { "mike", "mary", "stark", "jeff" };

    // 不指定，setprecision()表示设置整个数字的有效数字
    for( int i=0; i<4; i++ )
    {
        cout << setiosflags(ios_base::left)
            << setw(6) << names[i]
            << resetiosflags(ios_base::left) //清除左对齐设置
            << setw(10) << setprecision(1) << values[i] << endl;
    }

    // 指定为定点的形式，setprecision()表示设置小数点后面的有效数字
    cout << setiosflags(ios_base::fixed);
    for( int i=0; i<4; i++ )
    {
        cout << setiosflags(ios_base::left)
            << setw(6) << names[i]
            << resetiosflags(ios_base::left) //清除左对齐设置
            << setw(10) << setprecision(1) << values[i] << endl;
    }
    cout << resetiosflags(ios_base::fixed);

    // 指定为科学计数法的形式输出
    cout << setiosflags(ios_base::scientific);
    for( int i=0; i<4; i++ )
    {
        cout << setiosflags(ios_base::left)
            << setw(6) << names[i]
            << resetiosflags(ios_base::left) //清除左对齐设置
            << setw(10) << setprecision(1) << values[i] << endl;
    }
    cout << resetiosflags(ios_base::scientific);

    return 0;
}