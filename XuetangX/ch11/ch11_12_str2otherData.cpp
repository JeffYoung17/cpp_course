/*
 * 把 字符串 --转换--> 其他类型的数据
 **/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <class T>
inline T fromString( const string& str )
{
    istringstream in_str( str );
    T temp;
    in_str >> temp;
    return temp;
}

int main( int argc, char** argv )
{
    int val1 = fromString<int>("543");
    cout << val1 << endl;
    char val2 = fromString<char>("a");
    cout << val2 << endl;
    return 0;
}