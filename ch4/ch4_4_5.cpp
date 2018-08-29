/*
 * 类的基本操作
 * 初始化列表 声明的时候可以不写，定义的时候再写
 * 有参的构造函数
 * 默认构造函数
 * 委托构造函数
 * 复制构造函数 三种被调用的情况
 * 析构函数 最简单的情况 函数体为空 与系统在没有析构函数时默认生成的一样
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
    ~Clock();
    void setTime(int h, int m, int s);
    void showTime(void);
    Clock returnObj(void);
    void fun(Clock cl);

};

Clock returnObj(void)
{
    Clock cl; //这里会调用一次默认构造函数
    return cl;
}

int main(int argc, char**argv)
{
    Clock c1(21,31,0); //call constructor
    Clock c2(c1); //call copy constrcutor

    c2.fun(c1); //call copy constructor

    Clock temp_cl(1, 2, 3); //call constructor

    temp_cl = returnObj(); //这里这个等号叫赋值，把returnObj赋值给temp_cl不会调用复制构造函数，
    //调用的是默认的赋值运算符函数，简单情况用默认ojbk，其他情况以后会讲到，自己重新写一个赋值运算符函数。

    return 0;
}

Clock::Clock(int hour_fp, int min_fp, int sec_fp):hour(hour_fp), min(min_fp), sec(sec_fp)
{
    cout << "we are constructors, we do the same thing!" << endl;
}

/*
 * entrust constructor
**/
Clock::Clock():Clock::Clock(0, 0, 0)
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

Clock::~Clock(){}

void Clock::setTime(int h, int m, int s)
{
    hour = h;
    min = m;
    sec = s;
}

void Clock::showTime(void)
{
    cout << "now is " << hour << ":" << min << ":" << sec <<endl;
}

void Clock::fun(Clock cl)
{
    cl.showTime();
}