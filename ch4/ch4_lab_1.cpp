#include <iostream>
using namespace std;
class Integer {
private:
    int _num;
public:
    Integer(int num);
    Integer();
    int gcd(Integer b);
};
int main(){
    int a, b;
    cin >> a >> b;
    Integer A(a);
    Integer B(b);
    cout << A.gcd(B) << endl;
    return 0;
}

Integer::Integer(int num):_num(num){}
Integer::Integer():Integer::Integer(0){}
int Integer::gcd(Integer b)
{
    for(int i=(_num>b._num?b._num:_num); i>0; i--)
    {
        if(_num%i ==0 && b._num%i == 0)
        return i;
    }
}
