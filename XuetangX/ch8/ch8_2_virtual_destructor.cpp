/*
 * virtual析构函数
 * 这个例子: 避免了内存泄漏
**/

#include <iostream>
using namespace std;

class Base
{
public:
  virtual ~Base();
};

class Derived : public Base
{
private:
  int *ptr;

public:
  Derived();
  virtual ~Derived();
};

// 假设这个func()的作用是一个通用的析构函数，析构以Base为基类的对象
// 如果是静态绑定的情况，那么编译阶段，编译器只认为是Base指针，所以delete ptr的时候只会调用Base的析构函数
// 如果是动态绑定，那么func(&d)，就会去调用Derived的析构函数，首先执行派生类的析构，然后调用基类的析构
void func(Base *p)
{
  delete p;
}

int main()
{
  while (true)
  {

    Derived *pDer = new Derived();
    func(pDer);
  }
  return 0;
}

Base::~Base()
{
  cout << "Base destructor" << endl;
}

Derived::Derived()
{
  // 申请动态内存，保存的数据是整数0
  ptr = new int(0);
}

Derived::~Derived()
{
  // 在Derived的析构函数中把构造函数中申请的动态内存释放掉
  cout << "Derived destructor" << endl;
  delete ptr;
}