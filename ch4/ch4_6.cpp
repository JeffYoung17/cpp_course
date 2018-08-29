/*
 * 初始化列表 声明的时候可以不写，定义的时候再写
 * 有参的构造函数
 * 默认构造函数
 * 委托构造函数
 * 组合类的初始化
 * 析构函数暂时删了，反正也不做什么事情
**/
#include <iostream>
#include <cmath>

using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point(int xx, int yy);
    Point();
    Point(const Point &p);
    int getX(void);
    int getY(void);
    void setX(int xx);
    void setY(int yy);
};

class Line{
private:
    double len;
    Point p1, p2;
public:
    Line(Point xp1, Point xp2);
    Line(); // not defined yet
    Line(const Line &ln);
    double getLen(void);
};

int main(int argc, char** argv)
{
    Point mp1(1,1), mp2(3,4);
    Line mline1(mp1, mp2);
    Line mline2 = mline1; // or Line mline2(mline1);
    cout << "the length of line1 is " << mline1.getLen() << endl;
    cout << "the length of line2 is " << mline2.getLen() << endl;
    return 0;
}

Point::Point(int xx, int yy):x(xx), y(yy)
{
    x = xx;
    y = yy;
    cout << "i am a constructor of Point!" << endl;
}
Point::Point():Point::Point(0, 0)
{}

Point::Point(const Point &p)
{
    x = p.x;
    y = p.y;
    cout << "i am a copy constructor of Point!" << endl;
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

/*
 * 在线的有参构造函数中，传入两个点类的形参，用初始化列表的形式去初始化线的点类部件
**/
Line::Line(Point xp1, Point xp2):p1(xp1), p2(xp2)
{
    cout << "i am a constructor of Line" << endl;
    double delta_x = static_cast<double>(p1.getX() - p2.getX());
    double delta_y = static_cast<double>(p1.getY() - p2.getY());
    len = sqrt(delta_x*delta_x + delta_y*delta_y);
}

Line::Line(const Line &ln):p1(ln.p1), p2(ln.p2), len(ln.len)
{
    cout << "i am a copy constructor of Line" << endl;
}

double Line::getLen(void)
{
    return len;
}
