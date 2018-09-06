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
    vector<int> s(N);
    for( int i=0; i<N; i++ )
    {
        cin >> s[i];
    }
    //transform算法
    transform( s.begin(), s.end(), ostream_iterator<int>(cout, " "),\
        negate<int>() );
    cout << endl;
    return 0;
}