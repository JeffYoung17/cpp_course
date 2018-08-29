/*
 * 有继承的情况下，写构造函数需要注意的点比较多；
 * 所以这个例子对基类和派生类都没有显式地定义构造函数；
 * 公有继承方式：派生类可以访问public和protected,派生类的实例化对象可以访问public
 * 私有继承方式：派生类可以访问public和protected,派生类的实例化对象不能访问任何基类的成员\
 *      所以只好在派生类中派生出新的一些成员函数，在这个例子是同名的成员。
 * 保护继承,主要是基类中保护成员的作用：
 *      对派生类:和基类的public成员一样,在派生类中直接拿来用;
 *      对派生类的实例化对象:和private是一样的;
 *      即实现了代码重用,有实现了数据隐藏
**/
#include <iostream>
using namespace std;

class A {
protected:
    int x;
};

int main(int argc, char** argv) {
    A a;
    //错误 a.x = 5;
}

class B: public A{
public:
    void function();
};
void B::function() {
    x = 5;   //正确
}