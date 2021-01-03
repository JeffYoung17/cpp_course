/*
 * 初始化列表
 * 有参的构造函数
 * 默认构造函数
 * 委托构造函数
 * 析构函数
**/
#include <iostream>
#include <cmath>

using namespace std;

class Point{
private:
    int x;
    int y;
    static int count; // 静态数据成员的声明
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
    // 静态函数成员, 区别在于是否知道通过哪个具体的对象进行调用, 一般用来处理静态数据成员
    friend float distBetw2Pt(const Point& a, const Point& b);
};

float distBetw2Pt(const Point& a, const Point& b)
{
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

int Point::count = 0; // 静态数据成员的定义和初始化

int main(int argc, char** argv)
{
    Point::showCount();
    Point mp1(1,1);
    Point::showCount();
    Point mp2(mp1);
    Point::showCount();
    Point mp3(2,2);
    cout << "Dis is: " << distBetw2Pt(mp1, mp3) << endl;
    return 0;
}

Point::Point(int xx, int yy):x(xx), y(yy)
{
    count++;
    cout << "i am a constructor of Point!" << endl;
}

Point::Point():Point::Point(0, 0)
{}

Point::Point(const Point& p)
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
