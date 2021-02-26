/*
 * 抽象类规定了基类和各级派生类的统一的对外接口
**/

#include <iostream>
using namespace std;

class Base1
{
public:
  virtual void display() const = 0; // 纯虚函数
};

class Base2 : public Base1
{
public:
  virtual void display() const;
};
void Base2::display() const
{
  cout << "display() of Base2" << endl;
}

class Derived : public Base2
{
public:
  virtual void display() const;
};
void Derived::display() const
{
  cout << "display() of Derived" << endl;
}

void func(Base1 *ptr)
{
  ptr->display();
}

int main()
{
  Base2 base;
  Derived derived;
  func(&base);
  func(&derived);
  return 0;
}
