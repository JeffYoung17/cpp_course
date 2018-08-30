/*
 * 复数类的加减乘除重载：类的成员函数
 * << 重载：类的非成员函数
**/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0.0, double i = 0.0):real(r), imag(i) {}
    Complex operator + (const Complex& com) const;
    Complex operator - (const Complex& com) const;
    Complex operator * (const Complex& com) const;
    Complex operator / (const Complex& com) const;
    friend ostream& operator << (ostream& out, const Complex& com);
};

ostream& operator << (ostream& out, const Complex& com)
{
    out << com.real << " " << com.imag << endl;
    return out;
}

int main()
{
    double real, imag;
    cin >> real >> imag;
    Complex c1(real, imag);
    cin >> real >> imag;
    Complex c2(real, imag);
    cout << c1 + c2;
    cout << c1 - c2;
    cout << c1 * c2;
    cout << c1 / c2;
    return 0;
}

Complex Complex::operator+(const Complex& com) const {
    return Complex(real + com.real, imag + com.imag);
}

Complex Complex::operator-(const Complex& com) const {
    return Complex(real - com.real, imag - com.imag);
}

Complex Complex::operator*(const Complex& com) const {
    return Complex(real*com.real - imag*com.imag, imag*com.real + real*com.imag);
}

Complex Complex::operator/(const Complex& com) const {
    return Complex(\
        (real*com.real + imag*com.imag)/(com.real*com.real + com.imag*com.imag),\
        (imag*com.real - real*com.imag)/(com.real*com.real + com.imag*com.imag)\
    );
}
