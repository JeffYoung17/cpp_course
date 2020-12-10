/*
 * 为时钟类重载前置的++和后置的++,时间+1s；
 * 有默认值的函数，声明的时候加上默认值，定义的时候去掉默认值；或者声明的时候直接定义
 *  (*this)表示当前对象本身
**/

#include <iostream>

using namespace std;

class Clock{
private:
    int hour;
    int min;
    int sec;
public:
    Clock(int h, int m, int s);
    Clock();
    void displayTime(void) const;
    Clock& operator ++(void);
    Clock operator ++(int);
};

int main(int argc, char** argv)
{
    Clock cl(23, 44, 59);
    Clock cl_blank;
    cl.displayTime();
    cl_blank.displayTime();
    cl_blank = cl++;
    cl.displayTime();
    return 0;
}

Clock::Clock(int h, int m, int s) : hour(h), min(m), sec(s) {} 
Clock::Clock() : Clock::Clock(0, 0, 0) {}

void Clock::displayTime(void) const
{
    cout << hour << " " << min << " " << sec << endl;
}

Clock& Clock::operator ++(void)
{
    sec++;
    if(sec >= 60)
    {
        sec -= 60;
        min++;
        if(min >= 60)
        {
            min -= 60;
            hour = (hour++)%24;
        }
    }
    return *this;
}

Clock Clock::operator ++(int)
{
    Clock old = *this;
    ++(*this);
    return old;
}