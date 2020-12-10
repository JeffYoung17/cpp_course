#include <iostream>

using namespace std;

class Base1
{
public:
    Base1(int _x);
    ~Base1();
private:
    int x;
};

class Base2
{
public:
    Base2(int _y);
    ~Base2();
private:
    int y;
};

class Base3
{
public:
    Base3(int _z);
    ~Base3();
private:
    int z;
};

class Derived:public Base2, public Base1, public Base3
{
public:
    Derived(int x1, int x2, int x3, int x4);
    ~Derived();
private:
    int w;
};

int main(int argc, char** argv)
{
    int x[4];
    for (int i = 0; i < 4; ++i)
        cin >> x[i];
    Derived d(x[0], x[1], x[2], x[3]);
    return 0;
}

Base1::Base1(int _x):x(_x)
{
    cout << "Base1 constructor called " << x << endl;
}

Base1::~Base1()
{
    cout<<"Base1 destructor called"<<endl;
}

Base2::Base2(int _y):y(_y)
{
    cout << "Base2 constructor called " << y << endl;
}
Base2::~Base2()
{
    cout<<"Base2 destructor called"<<endl;
}

Base3::Base3(int _z):z(_z)
{
    cout << "Base3 constructor called " << z << endl;
}
Base3::~Base3()
{
    cout<<"Base3 destructor called"<<endl;
}

Derived::Derived(int x1, int x2, int x3, int x4):Base2(x3), Base1(x2), Base3(x4),w(x1)
{
    cout << "Derived constructor called " << w << endl;
}

Derived::~Derived()
{
    cout << "Derived destructor called" << endl;
}