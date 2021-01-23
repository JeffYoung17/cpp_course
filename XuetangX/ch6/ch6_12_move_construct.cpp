/*
 * 深层复制构造(初始化列表的形式)
 * 移动构造, 返回临时对象的优化
 * 因为现在这个版本的编译器有RVO，所以返回值是对象的时候并不会在构建临时对象的时候调用复制构造函数
 * -fno-elide-constructors: 关闭g++返回临时对象的优化
**/

#include <iostream>
using namespace std;

class IntNum{
private:
    int* ptr;
public:
    IntNum(int x);
    IntNum();
    ~IntNum();
    IntNum(const IntNum& obj);
    IntNum(IntNum&& obj);
    int getInt(void);
};

IntNum getNum(void)
{
    IntNum a;
    return a;
}

int main(int argc, char** argv)
{
    cout << getNum().getInt() << endl;
    return 0;
}

// new int(x)返回一个指针
IntNum::IntNum(int x) : ptr(new int(x))
{
    cout << "calling constructor" << endl;
}

IntNum::IntNum() : IntNum::IntNum(0)
{
    cout << "delegate constructor" << endl;
}

IntNum::~IntNum()
{
    delete ptr;
    cout << "deleting" << endl;
}

IntNum::IntNum(const IntNum& obj):ptr( new int(*obj.ptr) )
{
    cout << "calling copy constructor" << endl;
}

IntNum::IntNum(IntNum&& obj) : ptr(obj.ptr)
{
    // 看起来做了一次浅层复制,然后把obj的指针置为空指针，delete空指针不会报错
    obj.ptr = nullptr;
    cout << "calling move constructor" << endl;
}

int IntNum::getInt(void)
{
    return *ptr;
}