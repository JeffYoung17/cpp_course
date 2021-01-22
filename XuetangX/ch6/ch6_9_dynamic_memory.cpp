/**
 * 动态分配内存
 */
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
    Point* p_pt = new Point(1, 2);
    cout << p_pt->getY() << endl;
    p_pt->printCoor();
    delete p_pt;
    // p_pt指针变量是主函数的一个局部变量
    // delete: 释放指针变量指向的内存空间

    p_pt = new Point;
    cout << p_pt->getX() << endl;
    p_pt->printCoor();
    delete p_pt;
    return 0;
}

Point::Point(int xx, int yy):x(xx), y(yy)
{
    cout << "calling constructor" << endl;
}

Point::Point():Point::Point(0,0)
{
    cout << "default constructor" << endl;
}

Point::~Point()
{
    cout << "destructor" << endl;
}

Point::Point(const Point &p)
{
    x = p.x;
    y = p.y;
    cout << "copy constructor" << endl;
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

void Point::printCoor()
{
    cout << "coor is " << "(" << x << ", " << y << ")" << endl;
}

void Point::printCoor() const
{
    cout << "(" << x << ", " << y << "). " << "i dont modify object status" << endl;
}
