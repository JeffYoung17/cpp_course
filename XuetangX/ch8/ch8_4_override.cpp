/*
 * 
**/

#include <iostream>
using namespace std;

class Base final
{
public:
  virtual void display() const;
};
void Base::display() const
{
  cout << "display() of Base" << endl;
}

/** 错误，Base 声明为final, 不允许被继承
class Derived : public Base
{
public:
  virtual void display() const override; // 显示的函数覆盖, 若出错在编译期间可发现
};
void Derived::display() const
{
  cout << "display() of Derived" << endl;
}
*/

class Base1
{
public:
  virtual void display() const final;
};
void Base::display() const
{
  cout << "display() of Base" << endl;
}

/**
class Derived : public Base1
{
public:
  // 错误: 不允许覆盖基类中声明为final的成员函数
  virtual void display() const override; // 显示的函数覆盖, 若出错在编译期间可发现
};
void Derived::display() const
{
  cout << "display() of Derived" << endl;
}
*/

int main()
{
  return 0;
}
