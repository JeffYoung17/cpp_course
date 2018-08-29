#include <iostream>

using namespace std;

int fib(int num)
{
    if(num == 0)
    {
        return 1;
    }

    else if(num == 1)
    {
        return 1;
    }
    else
    {
        return fib(num-1)+fib(num-2);
    } 
}

int main(int argc, char** argv)
{
    int n = 0;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}