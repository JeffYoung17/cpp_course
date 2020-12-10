/*
 * 抽象类和dynamic_cast的结合使用，暂时搞不懂。。。
**/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Shape {
public:
    Shape() {}
    virtual ~Shape() {}
};

class Triangle : public Shape {
public:
    Triangle() {}
    ~Triangle() {}
};

class Rectangle : public Shape {
public:
    Rectangle() {}
    ~Rectangle() {}
};

int getVertexCount(Shape* ptr)
{
    if( Triangle* pT = dynamic_cast<Triangle*>(ptr) )
    {
        return 3;
    }

    else if( Rectangle* pR = dynamic_cast<Rectangle*>(ptr) )
    {
        return 4;
    }

    else if( Shape* pS = dynamic_cast<Shape*>(ptr) )
    {
        return 0;
    }
}

int main()
{
    Shape s;
    cout << getVertexCount(&s) << endl;
    Triangle t;
    cout << getVertexCount(&t) << endl;
    Rectangle r;
    cout << getVertexCount(&r) << endl;
    return 0;
}