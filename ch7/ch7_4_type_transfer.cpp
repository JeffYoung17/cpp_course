/*
 * 目的：编写通用的显示函数 fun()
 * 但是并没有成功
**/
#include <iostream>

using namespace std;

class Base1{
public:
    void display() const {
        cout << "i am display of Base1" << endl;
    }
};

class Base2 : public Base1 {
public:
    void display() const {
        cout << "i am display of Base2" << endl;
    }
};

class Derive : public Base2 {
public:
    void display() const {
        cout << "i am display of Derive" << endl;
    }
};

void fun(Base1* ptr) {
    ptr->display();
}

int main(int argc, char** argv)
{
    Base1 b1;
    Base2 b2;
    Derive d;
    b1.display();
    b2.display();
    d.display();
    fun(&b1);
    fun(&b2);
    fun(&d);

    return 0;
}