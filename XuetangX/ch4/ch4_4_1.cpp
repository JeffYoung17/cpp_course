/*
 * 类的基本操作
 * 初始化列表的形式
**/
#include <iostream>

using namespace std;

class Clock{
private:
    int hour = 0;  // 类内初始值
    int min;
    int sec;
public:
    Clock() = default; // 希望编译器生成隐含的默认构造函数
    Clock(int hour_fp, int min_fp, int sec_fp);
    void setTime(int h = 0, int m = 0, int s = 0);  // 带默认参数值
    void showTime(void);
};

int main(int argc, char**argv)
{
    Clock cl; // 调用隐含的默认构造函数,没有初始值的基本数据类型会随机初始化
    cl.showTime();
    cl.setTime(21,10,31);
    cl.showTime();
    return 0;
}

// 初始化列表
Clock::Clock(int hour_fp, int min_fp, int sec_fp):hour(hour_fp), min(min_fp), sec(sec_fp)
{
    cout << "constructor is called" << endl;
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