#include <iostream>

using namespace std;

int num = 0;

void move(char src, char dest)
{
    cout << src << "--->" << dest << endl;
}

void hano(int n, char src, char medium, char dest)
{
    num++;
    if(n == 1) {
        move(src, dest);
    }
    else {
        hano(n-1, src, medium, dest);
        move(src, dest);
        hano(n-1, medium, dest, src);
    }
}

int main(int argc, char** argv)
{
    
    cout << "enter the num of plate: " << endl;
    hano(10, 'A', 'B', 'C');
    cout << num << endl;
    return 0;
}