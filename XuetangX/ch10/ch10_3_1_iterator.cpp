/*
 * 输入实数，输出它的平方和
 * 用迭代器的方式实现
**/

#include <iostream>
#include <iterator>
#include <algorithm>

#include <functional>
#include <vector>

using namespace std;

double square(double x)
{
    return x * x;
}
int main()
{
    // 第二个输入流迭代器表示输入流的结束，没有参数，是用默认方式构造的；
    // windows: ctrl+z表示结束标志
    // linux: ctrl+d表示结束标志
    transform( istream_iterator<double>(cin), istream_iterator<double>(),\
        ostream_iterator<double>(cout, "\t"), square );
    cout << endl;
    return 0;
}