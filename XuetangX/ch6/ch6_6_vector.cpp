#include <iostream>
#include <vector>

using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point(int xx, int yy);
    Point();
    ~Point();
};

int main(int argc, char** argv)
{
    vector<int> arr(2);
    arr[0] = 0;
    arr[1] = 5;
    cout << arr[0] << " " << arr[1] << endl;
    cout << arr.size() << endl;

    //暂时可以理解为begin()和end()返回的是指针
    vector<double> array={1,2,3};
    for(auto ptr=array.begin(); ptr<array.end(); ptr++)
    {
        cout << *ptr << endl;
    }

    //基于范围的for循环
    for(auto ele:array)
    {
        cout << ele << endl;
    }

    vector<Point> p(2);
    
    return 0;
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