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
public:
    Point(int xx, int yy);
    Point();
    ~Point();
    Point(const Point &p);
    int getX(void);
    int getY(void);
    void setX(int xx);
    void setY(int yy);
    void printCoor();
    void printCoor() const;
};

int main(int argc, char** argv)
{
    Point p1(2,3);
    const Point p2(3,4);
    p1.printCoor();
    p2.printCoor();
    return 0;
}

Point::Point(int xx, int yy):x(xx), y(yy)
{
    cout << "calling constructor" << endl;
}

Point::Point():Point::Point(0,0)
{

}

Point::~Point(){}

Point::Point(const Point &p)
{
    x = p.x;
    y = p.y;
}

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

void Point::printCoor()
{
    cout << "coor is " << "(" << x << ", " << y << ")" << endl;
}

/*
 * 加了const,编译器会检查函数体内有没有改变
**/
void Point::printCoor() const
{
    cout << "(" << x << ", " << y << "). " << "i dont modify object status" << endl;
}
