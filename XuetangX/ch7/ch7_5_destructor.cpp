/*
 * 派生类的析构函数例子
**/
#include <iostream>
using namespace std;

class Base1 {   
public:
    Base1(int i) 
   { cout << "Constructing Base1 " << i << endl; }

    ~Base1() 
    { cout << "Destructing Base1" << endl; }
};
class Base2 {
public:
    Base2(int j) 
   { cout << "Constructing Base2 " << j << endl; }

    ~Base2() 
    { cout << "Destructing Base2" << endl; }
};
class Base3 {
public:
    Base3() { cout << "Constructing Base3 *" << endl; }
    ~Base3() { cout << "Destructing Base3" << endl; }
};

class Derived : public Base1, public Base2, public Base3{
public:
    Derived(int a, int b, int c, int d):Base1(a), Base2(b), m1(c), m2(d) {
        cout << "Derived Constructor" << endl;
    }
private:
    Base1 m1;
    Base2 m2;
    Base3 m3;
};

int main(int argc, char** argv)
{
    Derived obj(1,2,3,4);

    return 0;
}

