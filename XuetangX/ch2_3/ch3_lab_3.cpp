#include <iostream>

using namespace std;

bool decision_choushu(int num)
{
    int count = 0;
    for(int i=2; i<num; i++)
    {
        if(num%i ==0)
        {
            count++;
            if(i!=2 && i!=3 && i!=5)
            {
                return false;
            }
        }
    }

    if(count == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main(int argc, char** argv)
{
    int no = 0;
    cin >> no;
    if(decision_choushu(no) == false)
    {
        cout << "False" << endl;
    }
    else
    {
        cout << "True" << endl;
    }
    
    return 0;
}