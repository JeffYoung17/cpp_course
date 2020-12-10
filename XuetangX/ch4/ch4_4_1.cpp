/*
 * 类的基本操作
 * 初始化列表的形式
**/
#include <iostream>

using namespace std;

class Clock{
private:
    int hour;
    int min;
    int sec;
public:
    Clock(int hour_fp, int min_fp, int sec_fp):hour(hour_fp), min(min_fp),
        sec(sec_fp)
    {
        cout << "constructor is called" << endl;
    }
    void setTime(int h, int m, int s);
    void showTime(void);

};

int main(int argc, char**argv)
{
    Clock cl(21,9,30);
    cl.showTime();
    cl.setTime(21,10,31);
    cl.showTime();
    return 0;
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