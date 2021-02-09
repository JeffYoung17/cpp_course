/**
 * 基类和派生类的类型转换
 */
#include <iostream>
#include <cmath>

using namespace std;

class Base1 {
public:
    void display() const {
        cout << "Base1 display" << endl;
    }
};

class Base2 : public Base1 {
public:
    void display() const {
        cout << "Base2 display" << endl;
    }    
};

class Derived : public Base2 {
public:
    void display() const {
        cout << "Derived display" << endl;
    }
};

void fun(Base1 *ptr) {
    ptr->display();
}

int main()
{
    Base1 b1;
    Base2 b2;
    Derived d1;
    fun(&b1);
    fun(&b2);
    fun(&d1);

    return 0;
}