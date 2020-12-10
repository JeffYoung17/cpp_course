#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Equation{
private:
    int _a, _b, _c;
public:
    Equation(int a, int b, int c);
    void solve();
};

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    Equation tmp(a, b, c);
    tmp.solve();
    return 0;
}

Equation::Equation(int a, int b, int c):_a(a), _b(b), _c(c){}

void Equation::solve()
{
    if(_a!=0)
    {
        if(_b*_b-4*_a*_c > 0)
        {
            cout << 1 << endl;
            if(_a>0)
            {
                printf("%.2f %.2f\n",(-_b - sqrt(_b*_b-4*_a*_c))/(2*static_cast<double>(_a)),\
                    (-_b + sqrt(_b*_b-4*_a*_c))/(2*static_cast<double>(_a)));           
            }
            else{
                printf("%.2f %.2f\n",(-_b + sqrt(_b*_b-4*_a*_c))/(2*static_cast<double>(_a)),\
                    (-_b - sqrt(_b*_b-4*_a*_c))/(2*static_cast<double>(_a)));
            }
        }
        else if(_b*_b-4*_a*_c == 0)
        {
            cout << 2 << endl;
            printf("%.2f\n", -static_cast<double>(_b)/(2*_a) );            
        }
        else{
            cout << 3 << endl;
        }
    }

    else{
        if(_b!=0)
        {
            cout << 6 << endl;
            printf("%.2f\n",-_c/static_cast<double>(_b) );            
        }

        else if(_b==0 && _c!=0){
            cout << 4 << endl;
        }

        else if(_b==0 && _c==0){
            cout << 5 << endl;
        }

    }

}