/*
 * 这个例子对基类和派生类都没有显式地定义构造函数；
 * 私有继承：派生类可以访问public和protected, 属性均变为private;
 *      派生类的实例化对象不能访问任何基类的成员
**/

#include <iostream>
#include <cmath>

using namespace std;

class Point {   
    //基类Point类的定义
    public:     
    //公有函数成员
        void initPoint(float x = 0, float y = 0){ 
            this->x = x; 
            this->y = y;
        }
        void move(float offX, float offY){ 
            x += offX; 
            y += offY;
        }
        float getX() const { return x; }
        float getY() const { return y; }
    private:        
    //私有数据成员
        float x, y;
};

class Rectangle : private Point { 
// 派生类定义部分
public: 
// 新增公有函数成员
    void initRectangle(float _x, float _y, float _w, float _h) {
        initPoint(_x, _y);              // 调用基类公有成员函数
        this->w = _w;
        this->h = _h;
    }
    float getH() const { return h; }
    float getW() const { return w; }
    // 基类的公有接口不能通过派生类的对象访问, 因此实现新的move和getXY
    void move(float offX, float offY) {
        Point::move(offX, offY);
    }
    float getX() const { return Point::getX(); }
    float getY() const { return Point::getY(); }
private:    
// 新增私有数据成员
    float w, h;
};

int main(int argc, char** argv)
{
    Rectangle rect;
    rect.initRectangle(2, 3, 10, 20);
    rect.move(1, 0);
    cout << "the data of rect(x,y,w,h)" << endl;
    cout << rect.getX() << " " << rect.getY() << " ";
    cout << rect.getW() << " " << rect.getH() << endl;
    return 0;
}