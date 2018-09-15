/*
 * 栈stack的基本操作
 * 利用栈来实现反向输出一个单词的功能
**/
#include <iostream>
#include <stack>

using namespace std;

int main( int argc, char** argv )
{
    // char类型的栈s
    stack<char> s;
    // 输入字符串
    string str;
    cin >> str;
    // 利用迭代器把字符串的元素一个个放到栈里面
    for( string::iterator iter = str.begin(); iter != str.end(); ++iter )
    {
        s.push( *iter );
    }
    // 只要栈不为空，那么输出栈顶的元素，然后把栈顶元素弹出
    while( !s.empty() )
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;

    return 0;
}
