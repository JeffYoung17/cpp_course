#include <iostream>

using namespace std;

class Complex {
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    //只是把以下三个函数当成Complex类的友元函数，并不是类的成员函数；
    friend Complex operator + (const Complex &c1, const Complex &c2);
    friend Complex operator - (const Complex &c1, const Complex &c2);
    friend ostream & operator << (ostream &out, const Complex &c);
private:    
    double real;  //复数实部
    double imag;  //复数虚部
};

Complex operator + (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real+c2.real, c1.imag+c2.imag); 
}

Complex operator - (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real-c2.real, c1.imag-c2.imag);
}

ostream& operator << (ostream &out, const Complex &c)
{
    out << "(" << c.real << ", " << c.imag << ")";
    return out;
}

int main(int argc, char**argv)
{
    Complex c1(5, 4), c2(2, 10), c3; 
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    c3 = c1 - c2;   //使用重载运算符完成复数减法
    cout << "c3 = c1 - c2 = " << c3 << endl;
    c3 = c1 + c2;   //使用重载运算符完成复数加法
    cout << "c3 = c1 + c2 = " << c3 << endl;
    cout << "ojbk" << endl;
    return 0;
}

