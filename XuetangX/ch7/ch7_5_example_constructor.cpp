/*
 * 多继承加上组合类的例子
**/
#include <iostream>
using namespace std;

class Base1 {//基类Base1，构造函数有参数
public:
    Base1(int i) 
  { cout << "Constructing Base1 " << i << endl; }
};

class Base2 {//基类Base2，构造函数有参数
public:
    Base2(int j) 
  { cout << "Constructing Base2 " << j << endl; }
};

class Base3 {//基类Base3，构造函数无参数
public:
    Base3() 
  { cout << "Constructing Base3 *" << endl; }
};

class Derived : public Base1, public Base2, public Base3 {
public:
    Derived(int a, int b, int c, int d):Base1(a), Base2(b), m1(c), m2(d) {
        cout << "Constructing Derived" << endl;
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

