/*
 * 虚基类
**/
#include <iostream>
using namespace std;

class Base0 {   
public:
    Base0(int i) { cout << "Constructing Base0: " << i << endl; }
    ~Base0() { cout << "Destructing Base0" << endl; }
    int var0;
    void fun0() { cout << "mem of Base0" << endl; }
};

class Base1 : virtual public Base0 {   
public:
    Base1(int i) { cout << "Constructing Base1: " << i << endl; }
    ~Base1() { cout << "Destructing Base1" << endl; }
    int var1;
};

class Base2 : virtual public Base0 {
public:
    Base2(int j) { cout << "Constructing Base2: " << j << endl; }
    ~Base2() { cout << "Destructing Base2" << endl; }
    int var2;
};

class Derived : public Base1, public Base2 {
public:
    Derived(int a, int b) : Base2(a), Base1(b) {
        cout << "Derived Constructor" << endl;
    }
    int var;
    void fun() { cout << "mem of Derived" << endl; }
};

int main(int argc, char** argv)
{
    Derived obj(1, 4);
    obj.var0 = 2;
    // 没有冗余性, 直接访问Base1和Base2的共同基类Base0, 而不需要加作用域限定符
    obj.fun0(); 

    return 0;
}

