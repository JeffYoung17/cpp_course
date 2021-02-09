/*
 * 这个例子对基类和派生类都没有显式地定义构造函数；
 * 公有继承：派生类可以访问public和protected, 且属性不变;
 *      派生类的实例化对象可以访问public
 * 私有继承：派生类可以访问public和protected, 属性均变为private;
 *      派生类的实例化对象不能访问任何基类的成员
 * 保护继承: 派生类可以访问public和protected, 属性均变为protected;
 *      派生类的实例化对象不能访问任何基类的成员, 即实现了代码重用,又实现了数据隐藏
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