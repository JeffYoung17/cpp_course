/*
 * 类模板：存数据，取数据
 * 数据可以是基本类型的int，double，也可以是自定义的结构体，类
 * 当使用Store<int> s1, s2;编译器会把模板的类型参数换成int
 * 当使用Store<Student> s3;编译器会把模板的类型参数换成自定义的结构体Student
**/

#include <iostream>
#include <cstdlib>

using namespace std;

struct Student {
  int id;       //学号
  float gpa;    //平均分
}; 

template <class T>
class Store{
private:
    T item;
    bool haveValue;
public:
    Store();
    T& getElem();
    void putElem(const T& x);
};


template <class T>
Store<T>::Store() : haveValue(false) {}

template <class T>
T& Store<T>::getElem()
{
    if(!haveValue)
    {
        cout << "no elem now" << endl;
        exit(1);
    }
    return item;
}

template <class T>
void Store<T>::putElem(const T& x)
{
    haveValue = true;
    item = x;
}


int main(int argc, char** argv)
{
    Store<int> s1, s2;  
    s1.putElem(3);  
    s2.putElem(-7);
    cout << s1.getElem() << "  " << s2.getElem() << endl;

    Student g = { 1000, 23 };
    Store<Student> s3;
    s3.putElem(g); 
    cout << "The student id is " << s3.getElem().id << endl;

    Store<double> d;
    cout << "Retrieving object D... ";
    cout << d.getElem() << endl;
    return 0;
}