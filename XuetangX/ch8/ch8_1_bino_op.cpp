/*
 * 为复数类重载加法和减法
**/
#include <iostream>

using namespace std;

class Complex{
public:
    Complex(double r = 0.0, double i = 0.0);
    Complex operator+(const Complex &c2) const;
    Complex operator-(const Complex &c2) const;
    void display() const;
private:
    double real;
    double imag; 
};

int main(int argc, char** argv)
{
    Complex c1(1,2), c2(3,4), c3;
    c1.display();
    c2.display();
    c3.display();
    c3 = c2 - c1;
    c3.display();
    c3 = c2 + c1;
    c3.display();

    return 0;
}

Complex::Complex(double r, double i) : real(r), imag(i){}

Complex Complex::operator+(const Complex &com) const
{
    return Complex(real + com.real, imag + com.imag);
}

Complex Complex::operator-(const Complex &com) const
{
    return Complex(real - com.real, imag - com.imag);
}

void Complex::display(void) const
{
    cout << "(" << real << ", " << imag << ")" << endl;
}