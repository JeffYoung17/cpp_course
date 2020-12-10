/*
 * 当基类没有默认构造函数，那么派生类的构造函数中肯定要通过初始化列表的方法给基类传参数
 * 当基类有默认构造函数，那么派生类的构造函数可以不选择给基类传参数
**/
#include <iostream>
using namespace std;

class B {
public:
    B();
    B(int i);
    ~B();
    void print() const;
private:
    int b;
};

class C: public B {
public:
    C();
    C(int j);
    ~C();
    void print() const;
private:
    int c;
};

int main(int argc, char** argv)
{
    C obj(3);
    obj.print();

    return 0;
}

B::B() {
    b = 0;
    cout << "B's default constructor called." << endl;
}
B::B(int i) {
    b=i;
    cout << "B's constructor called." << endl;
}
B::~B() {
    cout << "B's destructor called." << endl;
}
void B::print() const {
    cout << b << endl;
}

C::C()
{
    c=0;
    cout << "C's default constructor" << endl;
}

C::C(int j)
{
    c = j;
    cout << "C's constructor" << endl;
}

C::~C()
{
    cout << "C's destructor" << endl;
}

void C::print() const
{
    B::print();
    cout << c << endl;
}