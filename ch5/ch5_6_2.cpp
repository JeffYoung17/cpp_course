/*
 * 常成员函数
 * const 也可以作为函数重载的形式
**/
#include <iostream>
#include <cmath>

using namespace std;

class Point{
private:
    int x;
    int y;
    const int a; //常数据成员
    static const int b; //静态常数据成员
public:
    Point(int xx, int yy, int val);
    Point();
    int getX(void);
    int getY(void);
    void setX(int xx);
    void setY(int yy);
    void printCoor() const;
};

const int Point::b = 10;

int main(int argc, char** argv)
{
    Point p1(2,3,1);
    const Point p2(3,4,1);
    p1.printCoor();
    p2.printCoor();
    return 0;
}

Point::Point(int xx, int yy, int val):x(xx), y(yy), a(val)
{
    cout << "calling constructor" << endl;
}

Point::Point():Point::Point(0,0,0)
{}

int Point::getX(void)
{
    cout << x << endl;
}
int Point::getY(void)
{
    cout << y << endl;
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
 * 加了const,编译器会检查函数体内有没有改变
**/
void Point::printCoor() const
{
    cout << "(" << x << ", " << y << "). " << "i dont modify object status" << endl;
    cout << a << endl;
}
