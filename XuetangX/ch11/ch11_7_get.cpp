/*
 * 使用get函数输入字符
**/

#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
    char ch;
    while( (ch = cin.get()) != EOF) 
    {
        cout.put(ch);
    }

    return 0;
}