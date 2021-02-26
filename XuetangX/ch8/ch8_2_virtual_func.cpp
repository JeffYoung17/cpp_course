/*
 * 通过虚函数，编写通用的显示函数，实现多态性，是一种动态绑定
**/

#include <iostream>
using namespace std;

class Base1
{
public:
  virtual void display() const;
};

class Base2 : public Base1
{
public:
  virtual void display() const;
};

class Derived : public Base2
{
public:
  virtual void display() const;
};

void func(Base1 &ptr)
{
  ptr.display();
}

// 因为公有派生类的对象可以初始化为基类的引用，也可以隐含转为基类的指针
// 所以这个func()函数有两种写法
// void func(Base1* ptr)

int main()
{
  Base1 b1;
  Base2 b2;
  Derived d;
  func(b1);
  func(b2);
  func(d);
  return 0;
}

void Base1::display() const
{
  cout << "display() of Base1" << endl;
}

void Base2::display() const
{
  cout << "display() of Base2" << endl;
}

void Derived::display() const
{
  cout << "display() of Derived" << endl;
}