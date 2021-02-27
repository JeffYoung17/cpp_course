/*
 * 
**/

#include <iostream>
using namespace std;

class Base
{
public:
  virtual void display() const;
};
void Base::display() const
{
  cout << "display() of Base" << endl;
}

class Derived : public Base
{
public:
  // virtual void display(); // 如果少写了const,就没有覆盖基类中的虚函数
  virtual void display() const override; // 显示的函数覆盖, 若出错在编译期间可发现
};
void Derived::display() const
{
  cout << "display() of Derived" << endl;
}

void func(Base *ptr)
{
  ptr->display();
}

int main()
{
  Base base; // 这个基类不是抽象类 所以可以实例化
  Derived derived;
  func(&base);
  func(&derived);
  derived.Base::display();
  return 0;
}
