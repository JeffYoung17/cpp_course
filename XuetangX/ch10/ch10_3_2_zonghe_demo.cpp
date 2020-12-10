/*
 * 综合运用迭代器的实例
 * 自定义一个排序函数模板, 能够按从小到大顺序输出容器内的元素
**/
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;


// 容器名.begin() 返回 指向容器第一个元素的迭代器;
// 容器名.end() 返回 指向容器最后一个元素的迭代器;
//  
template <class T, class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result)
{
    vector<T> s;

    for( ; first!=last; ++first )
    {
        // vector容器的成员函数push_back(), 把一个元素压到容器的尾部;
        // 从头开始, 通过(*first)压到尾部, 然后first自增;
        s.push_back(*first);
    }
    // sort函数对容器s里面的数据进行排序;
    sort( s.begin(), s.end() );
    // copy函数, 排序完成, 把结果送给 result迭代器 代表的输出位置
    copy( s.begin(), s.end(), result );
}

int main( int argc, char** argv )
{
    double a[5] = {1.2, 2.4, 0.8, 3.3, 3.2};
    mySort<double>( a, a+5, ostream_iterator<double>(cout, " ") );
    cout << endl;
    
    // 第二个输入流迭代器表示输入流的结束，没有参数，是用默认方式构造的；
    // windows: ctrl+z表示结束标志
    // linux: ctrl+d表示结束标志
    mySort<int>(istream_iterator<int>(cin), istream_iterator<int>(),\
        ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}