/*
 * 动态数组类
**/
#include <iostream>
#include <cassert>
#include <stdlib.h>

using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point(int xx, int yy);
    Point();
    ~Point();
    void getXY(void);
    void setXY(int x_coor, int y_coor);
};

class DynPoint{
private:
    int arr_size;
    Point *arr_ptr;
public:
    DynPoint(int s);
    DynPoint();
    ~DynPoint();
    Point& element(int index);
};

int main(int argc, char** argv)
{
    DynPoint dp(2);
    dp.element(0).setXY(1,2);
    dp.element(1).setXY(2,3);
    dp.element(0).getXY();
    dp.element(1).getXY();
    DynPoint dp_copy(dp);
    dp_copy.element(0).getXY();
    dp_copy.element(1).getXY();
    return 0;
    // 程序结束的时候会出错, 多次析构同一块内存空间
}

Point::Point(int xx, int yy):x(xx), y(yy)
{
    cout << "constructing point" << endl;
}

Point::Point():Point::Point(0,0)
{}

Point::~Point()
{
    cout << "destructing point" << endl;
}

void Point::setXY(int x_coor, int y_coor)
{
    x = x_coor;
    y = y_coor;
}

void Point::getXY(void)
{
    cout << "coor: X is " << x << " Y is " << y << endl;
}

DynPoint::DynPoint(int s):arr_size(s)
{
    cout << "requesting!" << endl;
    arr_ptr = new Point[arr_size];
}

DynPoint::DynPoint():DynPoint::DynPoint(1)
{}

DynPoint::~DynPoint()
{
    delete[] arr_ptr;
    cout << "deleting!" << endl;
}

Point& DynPoint::element(int index)
{
    assert(index >= 0 && index < arr_size);
    return arr_ptr[index];
}