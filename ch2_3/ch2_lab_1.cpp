#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int num = 0;
    cin >> num;
    int* ptr = new int[num];
    for(int i=0; i<num; i++) {
        cin >> ptr[i]; 
    }

    int count = 0;
    int max,min = ptr[0];
    for(int i=0; i<num; i++) {
        count += ptr[i];
        if(ptr[i] > max) {
            max = ptr[i];
        }
        if(ptr[i] < min) {
            min = ptr[i];
        }
    }

    cout << count << " " << min << " " << max << endl;

    delete[] ptr;

    return 0;
}