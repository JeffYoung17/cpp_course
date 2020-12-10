#include <iostream>
using namespace std;
  
class Mouse{
private:
public:
    static int mouse_num;
    Mouse();
    ~Mouse();
    Mouse(const Mouse& m);

};
  
void fn(Mouse m);

int Mouse::mouse_num = 0;

int main()
{
    Mouse a;
    cout << Mouse::mouse_num << endl;
    Mouse b(a);
    cout << Mouse::mouse_num << endl;
    for (int i = 0; i < 10; ++i)
    {
        Mouse x;
        cout << Mouse::mouse_num << endl;
    }
    fn(a);
    cout << Mouse::mouse_num << endl;
    return 0;
}
  
void fn(Mouse m)
{
    cout << Mouse::mouse_num << endl;
    Mouse n(m);
    cout << Mouse::mouse_num << endl;
}

Mouse::Mouse()
{
    mouse_num++;
}

Mouse::Mouse(const Mouse& m)
{
    mouse_num++;
}

Mouse::~Mouse()
{
    mouse_num--;
}