/*
 * 顺序容器的接口的简单使用
 * 按存放顺序打印容器内的所有元素
**/
#include <iostream>
#include <iterator>
#include <list>
#include <deque>

using namespace std;

// 输入参数 const char* msg:  
// 输入参数 const T& s: 代表对模板类型的常引用
template <class T>
void printContainer( const char* msg, const T& s )
{
    cout << msg << ": ";
    copy( s.begin(), s.end(), ostream_iterator<int>(cout, " ") );

    cout << endl;
}

int main( int argc, char** argv )
{
    // 把输入的数据逆向存进来
    deque<int> s;
    for( int i=0; i<4; i++)
    {
        int x;
        cin >> x;
        s.push_front(x);
    }
    printContainer("deque at first", s);
    
    // 列表把上面双端队列的数据逆向存放
    list<int> li(s.rbegin(), s.rend());
    printContainer("list at first", li);

    // 把列表容器里面的相邻元素互换一下位置
    list<int>::iterator iter = li.begin();
    while( iter != li.end() )
    {
        int v = *iter;
        iter = li.erase(iter);
        li.insert(++iter, v);
    }
    printContainer("list at last", li);

    // 用列表li容器的元素给双端队列s容器赋值，输出s
    s.assign( li.begin(), li.end() );
    printContainer("deque at last", s);

    return 0;
}
