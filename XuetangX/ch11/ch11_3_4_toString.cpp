/*
 * 向程序中的字符串输出
 * 格式转换功能：其他类型的数据 --转-> 字符串
**/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <class T>
inline string toString(const T& v)
{
    ostringstream out_string;
    out_string << v;
    return out_string.str();
}

int main( int argc, char** argv )
{
    // 对于所有基本类型都可以用这个函数
    // 如果是自定义的类，需要重载插入运算符<<

    string str1 = toString(5);
    cout << str1 << endl;

    string str2 = toString(1.2);
    cout << str2 << endl;

    string str3 = toString("hello world!");
    cout << str3 << endl;

    return 0;
}