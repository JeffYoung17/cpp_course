/*
 * 顺序容器的特性
 * 奇偶排序
 * 先从大到小输出奇数, 然后从小到大输出偶数
**/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>

using namespace std;

int main( int argc, char** argv )
{
    // 通过这样一对输入流, 输入int类型的数据
    istream_iterator<int> i1(cin), i2;
    vector<int> s1(i1, i2);
    sort(s1.begin(), s1.end());

    deque<int> s2;
    for( vector<int>::iterator iter = s1.begin(); iter != s1.end(); ++iter )
    {
        if( *iter%2 == 0)
            s2.push_back(*iter);
        else
            s2.push_front(*iter);
    }
    // 把处理完的双端队列容器中的元素用copy函数送给输出流迭代器, 送到终端
    copy( s2.begin(), s2.end(), ostream_iterator<int>(cout, " ") );
    cout << endl;
    return 0;
}