/*
 * 这个例子对基类和派生类都没有显式地定义构造函数；
 * 公有继承：派生类可以访问public和protected, 且属性不变;
 *      派生类的实例化对象可以访问public
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

// Rectangle在Point基础上添加宽和高, 进行继承
class Rectangle: public Point { 
// 派生类定义部分
public: 
    // 新增公有函数成员
    void initRectangle(float _x, float _y, float _w, float _h) {
        initPoint(_x, _y);              // 调用基类public成员
        this->w = _w;
        this->h = _h;
    }
    float getH() const { return h; }
    float getW() const { return w; }
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