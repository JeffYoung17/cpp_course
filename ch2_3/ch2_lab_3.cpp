#include <iostream>
using namespace std;

void printstar(int n);

int main()
{
    int num = 0;
    cin >> num;
    printstar(num);
    return 0;
}

void printstar(int n) 
{  
    for(int i=0; i<2*n-1; i++) 
    { 
        for(int j=0; j<2*n-1; j++) 
        { 
            if(i<n) 
            { 
                if(j>=n-i-1&&j<n+i) 
                { 
                    cout << "*"; 
                } 
                else 
                { 
                    cout << " "; 
                } 
            } 
            else 
            { 
                if(j>=i-n+1&&j<3*n-i-2) 
                { 
                    cout << "*"; 
                } 
                else  
                { 
                    cout << " "; 
                } 
            } 
 
        } 
        cout << endl;
    } 
}