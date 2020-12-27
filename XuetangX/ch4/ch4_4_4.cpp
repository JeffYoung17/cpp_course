/*
 * 类的基本操作
 * 初始化列表 声明的时候可以不写，定义的时候再写
 * 有参的构造函数
 * 默认构造函数
 * 委托构造函数
 * 复制构造函数 三种被调用的情况
**/
#include <iostream>

using namespace std;

class Clock{
private:
    int hour;
    int min;
    int sec;
public:
    Clock(int hour_fp, int min_fp, int sec_fp);
    Clock();
    Clock(const Clock &cl);
    void setTime(int h, int m, int s);
    void showTime(void) const;
    void fun(Clock cl);
};

void fun1(Clock cl)
{
    cl.showTime();
}

Clock fun2(void)
{
//    Clock tmp(8, 8, 8); // 这里会调用一次构造函数
//    cout << &tmp << endl;
//    return tmp; // 会生成一个临时对象返回给主调函数, 调用拷贝构造, 
    return Clock(8, 8, 8); // 这样的写法可以避免一次拷贝构造
    // 然而g++默认是有返回值优化选项, -fno-elide-constructors可以关闭优化
}

void show(const Clock &cl)
{
    cout << &cl << endl;
    cl.showTime();
}

int main(int argc, char**argv)
{
    Clock c1(21,31,0); // call constructor
    // condition 1: call copy constrcutor
    Clock c2(c1);

    // condition 2
    fun1(c1);

    // condition 3
    show(fun2());

    // Clock temp_cl(1, 2, 3); // call constructor
    // temp_cl = fun2(); //这里这个等号叫赋值，把fun2返回值赋值给temp_cl不会调用复制构造函数，
    // 调用的是默认的赋值运算符函数，根据情况重写一个赋值运算符函数。
    return 0;
}

Clock::Clock(int hour_fp, int min_fp, int sec_fp):hour(hour_fp), min(min_fp), sec(sec_fp)
{
    cout << "we are constructors, we do the same thing!" << endl;
}

/*
 * delegate constructor
**/
Clock::Clock() : Clock::Clock(0, 0, 0)
{
    /*
    cout << "we are constructors, we do the same thing!" << endl;
    */
}

Clock::Clock(const Clock &cl)
{
    hour = cl.hour;
    min = cl.min;
    sec = cl.sec;
    cout << "calling copy constructor" << endl;
}

void Clock::setTime(int h, int m, int s)
{
    hour = h;
    min = m;
    sec = s;
}

void Clock::showTime(void) const
{
    cout << "now is " << hour << ":" << min << ":" << sec <<endl;
}
