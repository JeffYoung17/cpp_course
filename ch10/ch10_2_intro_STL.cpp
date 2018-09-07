/*
 * 输入几个整数，存入向量容器，输出它们的相反数
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
    // transform算法
    // s.begin和s.end是迭代器，表示了容器的起始和结尾
    // 处理的结果依次送给输出流迭代器，处理一个容器中的元素，然后就送给这个迭代器
    // 处理容器中元素的方法，是用函数对象negate
    transform( s.begin(), s.end(), ostream_iterator<int>(cout, " "),\
        negate<int>() );
    cout << endl;
    return 0;
}