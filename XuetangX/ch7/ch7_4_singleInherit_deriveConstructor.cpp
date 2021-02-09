/*
 * 基类没有默认构造函数，派生类的构造函数要通过初始化列表的方法给基类传参数
 * 基类有默认构造函数，派生类的构造函数可以不选择给基类传参数
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
    C(int i, int j);
    ~C();
    void print() const;
private:
    int c;
};

int main(int argc, char** argv)
{
    C obj(1, 3);
    obj.print();
    C default_obj;
    default_obj.print();
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
    cout << "C's default constructor called" << endl;
}

C::C(int i, int j) : B(i), c(j)
{
    cout << "C's constructor called" << endl;
}

C::~C()
{
    cout << "C's destructor called" << endl;
}

void C::print() const
{
    B::print();
    cout << c << endl;
}