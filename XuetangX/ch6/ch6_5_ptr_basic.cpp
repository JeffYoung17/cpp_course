#include <iostream>

using namespace std;

int main()
{
    int i = 1;
    int* intPtr = &i;
    cout << "address of i: " << intPtr << endl;
    *intPtr = 3;
    cout << "i: " << i << endl;
    return 0;
}