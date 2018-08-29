/*
 * 初始化列表 声明的时候可以不写，定义的时候再写
 * 有参的构造函数
 * 默认构造函数
 * 委托构造函数
 * 析构函数派上了用场
**/
#include <iostream>
#include <cmath>

using namespace std;

class Point{
private:
    int x;
    int y;
    static int count;
public:
    Point(int xx, int yy);
    Point();
    ~Point();
    Point(const Point &p);
    int getX(void);
    int getY(void);
    void setX(int xx);
    void setY(int yy);
    static void showCount(void);
};

int Point::count = 0;

int main(int argc, char** argv)
{
    Point::showCount();
    Point mp1(1,1);
    Point::showCount();
    Point mp2(mp1);
    Point::showCount();
    return 0;
}

Point::Point(int xx, int yy):x(xx), y(yy)
{
    count++;
    cout << "i am a constructor of Point!" << endl;
}
Point::Point():Point::Point(0, 0)
{}

Point::Point(const Point &p)
{
    x = p.x;
    y = p.y;
    count++;
    cout << "i am a copy constructor of Point!" << endl;
}

Point::~Point()
{
    count--;
    cout << "i am a destructor of Point!" << endl;
}

int Point::getX(void)
{
    return x;
}
int Point::getY(void)
{
    return y;
}
void Point::setX(int xx)
{
    x = xx;
}
void Point::setY(int yy)
{
    y = yy;
}

void Point::showCount(void)
{
    cout << count << endl;
}
