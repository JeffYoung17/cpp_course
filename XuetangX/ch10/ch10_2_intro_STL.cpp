/*
 * 输入几个整数, 存入向量容器, 输出它们的相反数
**/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

int main( int argc, char** argv )
{
    const int N = 3;
    // s(N)一个容器
    vector<int> s(N);
    for( int i=0; i<N; i++ )
    {
        cin >> s[i];
    }
    // transform算法, 参数包括vector容器的迭代器, 函数对象, 以及结果
    // s.begin和s.end是迭代器, 表示了容器的起始和结尾, 起循环的作用;
    // negate函数对象处理的结果送给transform函数的result参数, 这里送给输出流迭代器;
    transform( s.begin(), s.end(), ostream_iterator<int>(cout, " "),\
        negate<int>() );
    cout << endl;
    return 0;
}