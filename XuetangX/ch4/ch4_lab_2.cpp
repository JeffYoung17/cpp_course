#include <iostream>
#include <cmath>
using namespace std;
 
class Integer{
private:
    int _num;
    int getLength() const;
public:
    Integer(int num);
    Integer();
    int inversed();
};
 
int main() {
    int n;
    cin >> n;
    Integer integer(n);
    cout << integer.inversed() << endl;
    return 0;
}

int Integer::getLength() const
{
    int len = 1;
    for(int i=1; i<_num; i=i*10)
    {
        if(_num/i >= 0 && _num/i < 10)
        {
            return len;
        }
        else
        {
            len++;
        }
    }
}

Integer::Integer(int num):_num(num){}
Integer::Integer():Integer::Integer(0){}
int Integer::inversed()
{
    int length = getLength();
    int result = 0;
    int temp = 0;
    for(int i=1; i<=length; i++)
    {
        temp = _num /static_cast<int>(pow(10,i-1)) %10;
        result += temp* static_cast<int>(pow(10,length-i)); 
    }
    return result;
}