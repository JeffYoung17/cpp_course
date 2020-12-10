#include <iostream>

using namespace std;

bool dec_ra(int a, int b, int c)
{

    if(a>b&&a>c)
    {
        if(a*a == b*b + c*c)
        return true;
    }

    else if(b>a&&b>c)
    {
        if(b*b == a*a + c*c)
        return true;
    }

    else
    {
        if(c*c == a*a + b*b)
        return true;
    }

    return false;
}

int main(int argc, char** argv)
{
    int edge1, edge2, edge3 = 0;
    cin >> edge1 >> edge2 >>edge3;
    if(dec_ra(edge1, edge2, edge3) == true)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}