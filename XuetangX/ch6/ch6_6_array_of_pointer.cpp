/**
 * 指针数组
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int line1[] = {1, 2, 3};
    int line2[] = {4, 5, 6};
    int line3[] = {7, 8, 9};

    int* pLine[3] = {line1, line2, line3};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << pLine[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}