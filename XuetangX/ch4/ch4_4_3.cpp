/*
 * 类的基本操作
 * 初始化列表 声明的时候可以不写，定义的时候再写
 * 有参的构造函数
 * 默认构造函数
 * 委托构造函数
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
    void setTime(int h, int m, int s);
    void showTime(void);

};

int main(int argc, char**argv)
{
    Clock cl(21,31,0);
    cl.showTime();
    cl.setTime(21,10,31);
    cl.showTime();
    Clock ccl;
    ccl.showTime();
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

