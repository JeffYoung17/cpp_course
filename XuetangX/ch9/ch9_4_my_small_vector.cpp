/*
 * 实现一个简单的动态数组的类模板；
**/
#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class Array{
private:
    T* list;
    int size;
public:
    Array(int sz = 50);
    Array(const Array<T>& arr);
    ~Array();

    Array<T>& operator =(const Array<T>& rhs);

    //重载运算符下标访问运算符函数, 用来访问动态数组的元素，还可以检查下标是否越界；
    //对应的有一份常成员函数，用来处理常对象
    T& operator [](int i);
    const T& operator [](int i) const;

    //重载指针转换运算符函数,用来将动态数组类的对象名字转换为指向T类型的指针，代表首地址；
    //对应的有一份常常成员函数，用来处理常对象；
    //指向常量的指针，不能通过指针来修改数组元素的值
    operator T*();
    operator const T*() const;

    int getSize() const;
    void resize(int sz);
};

void read(int* ptr, int n)
{
    for(int i=0; i<n; i++)
        cin >> ptr[i];
}

int main(int argc, char** argv)
{
    int arr[3];
    read(arr, 3);
    Array<int> arr_dyn(3);
    read(arr_dyn, 3);
    return 0;
}

//有默认值的函数定义的时候不要写默认值，声明的时候写上就可以了；
template <class T> Array<T>::Array(int sz)
{
    assert(sz >= 0);
    size = sz;
    list = new T[size];
}

template <class T> Array<T>::~Array()
{
    delete[] list;
}

template <class T> Array<T>::Array(const Array<T>& arr)
{
    size = arr.size;
    list = new T[size];
    for(int i=0; i<size; i++)
    {
        list[i] = arr.list[i];
    }
}

template <class T> int Array<T>::getSize() const
{
    return size;
}

template <class T> void Array<T>::resize(int sz)
{
    assert(sz >= 0);
    if(sz == size)
        return;
    T* newList = new T[sz];
    int n = (sz < size)?sz:size;
    for(int i=0; i<n; i++)
    {
        newList[i] = list[i];
    }
    delete[] list;
    list = newList;
    size = sz;
}

template <class T> Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
    if(&rhs != this) {
        if(size != rhs.size) {
            delete[] list;
            size = rhs.size;
            list = new T[size];
        }

        for(int i=0; i<size; i++)
        {
            list[i] = rhs.list[i];
        }
    }
    return *this;
}

template <class T>
T& Array<T>::operator [](int i)
{
    assert(i >= 0 && i < size);
    return list[i];
}

template <class T>
const T& Array<T>::operator [](int i) const
{
    assert(i >= 0 && i < size);
    return list[i];
}

template <class T>
Array<T>::operator T* ()
{
    return list;
}

template <class T>
Array<T>::operator const T* () const
{
    return list;
}
