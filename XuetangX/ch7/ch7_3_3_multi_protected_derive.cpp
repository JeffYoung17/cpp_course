#include <iostream>
using namespace std;

class A {
public:
    void setA(int);
    void showA() const;
private:
    int a;
};

class B {
public:
    void setB(int);
    void showB() const;
private:
    int b;
};

class C : public A, private B { 
public:
    void setC(int, int, int);
    void showC() const;
private:
    int c;
};

int main(int argc, char** argv)
{
    C obj;
    obj.setA(3);
    obj.showA();
    //错误 obj.setB(4);
    //错误 obj.showB();
    obj.setC(1, 2, 3);
    obj.showC();
    
    return 0;
}

void A::showA() const{
    cout << a << endl;;
}

void A::setA(int _x) {
    a = _x;
}

void B::showB() const{
    cout << b << endl;
}

void B::setB(int _y) {
    b = _y;
}

void C::showC() const{
    cout << c << endl;
}

void C::setC(int _x, int _y, int _z) {
    setA(_x);
    setB(_y);
    c = _z;
}
