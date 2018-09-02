#include <iostream>

using namespace std;

template<typename T>
T abs(T x)
{
    return x<0 ? -x:x;
}

int main(int argc, char** argv)
{
    double pi = 3.14;
    double n = -1.23;
    cout << abs(pi) << endl;
    cout << abs(n) << endl;
    return 0;
}