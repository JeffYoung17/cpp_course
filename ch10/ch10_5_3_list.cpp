/*
 * 列表容器的splice操作
 * 拼接操作
**/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <deque>

using namespace std;

int main( int argc, char** argv )
{
    // 两个string类型的数组, 存放人名
    string names1[] = { "Alice", "Helen", "Lucky", "Susan" };
    string names2[] = { "Bob", "David", "Levin", "Mike" };

    // 定义并且初始化列表容器s1和s2
    list<string> s1(names1, names1 + 4);
    list<string> s2(names2, names2 + 4);

    // 把s1的首迭代器指向的元素 放到 s2的尾部
    s2.splice(s2.end(), s1, s1.begin() );
    
    // iter1 是 s1的首迭代器
    list<string>::iterator iter1 = s1.begin();
    // iter1前进2个位置, 指向s1的第3个元素
    advance( iter1, 2 );
    
    // iter2 是 s2的首迭代器
    list<string>::iterator iter2 = s2.begin();
    // iter2前进1个位置, 指向s2的第2个元素
    ++iter2;

    // 用iter2初始化iter3
    list<string>::iterator iter3 = iter2;
    // iter3前进2个位置, 指向s2的第4个元素
    advance( iter3, 2 );

    // 把s2的 iter2到iter3迭代器范围内指向的元素: 也就是第2个元素到第4个元素
    // 放到s1的 iter1迭代器指向的元素之前: 也就是放到s1的第3个元素之前
    s1.splice( iter1, s2, iter2, iter3 );

    // 输出s1 和 s2
    copy( s1.begin(), s1.end(), ostream_iterator<string>(cout, " ") );
    cout << endl;
    copy( s2.begin(), s2.end(), ostream_iterator<string>(cout, " ") );
    cout << endl;

    return 0;
}