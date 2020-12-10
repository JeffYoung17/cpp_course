/*
 * 使用抽象类提供统一的对外接口
 * 纯虚函数的写法
 * 派生出具体的类实现具体的功能
**/
#include <iostream>

using namespace std;

const double pi = 3.14;

class Shape {
private:
public:
    Shape() {}
    ~Shape() {}
    virtual double getArea() = 0;
    virtual double getPerim() = 0;

};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    ~Circle() {}
    virtual double getArea();
    virtual double getPerim();
};

int main()
{
    double radius;
    cin >> radius;
    Circle c(radius);
    cout << c.getArea() << " " << c.getPerim() << endl;
    return 0;
}

double Circle::getArea()
{
    return pi*radius*radius;
}

double Circle::getPerim()
{
    return 2*pi*radius;
}