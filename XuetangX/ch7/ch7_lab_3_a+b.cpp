#include <iostream>
using namespace std;

class Base1
{
public:
    int x;
    Base1(int _x);
};
 
class Base2
{
public:
    int y;
    Base2(int _y);
};
 
class Derived : public Base1, public Base2
{
public:
    int z;
    Derived(Base1& a, Base2& b);
};

int main(int argc, char** argv)
{
    int x, y;
    cin >> x >> y;
    Base1 a(x);
    Base2 b(y);
    Derived d(a, b);
    cout << d.Base1::x << "+" << d.Base2::y << "=" << d.z << endl;
    return 0;
}

Base1::Base1(int _x) : x(_x){}

Base2::Base2(int _y) : y(_y){}

Derived::Derived(Base1& a, Base2& b) : Base1(a.x), Base2(b.y)
{
    z = a.x + b.y;    
}