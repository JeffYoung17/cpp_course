#include <iostream>

using namespace std;

void rowSum(int arr[][3], int nRow)
{
    for (int i = 0; i < nRow; ++i) {
        for (int j = 1; j < 3; ++j) {
            arr[i][0] += arr[i][j];
        }
    }
}

int main()
{
    int array[2][3] = {{1,2}, {2,3}};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    rowSum(array, 2);
    for (int i = 0; i < 2; ++i) {
        cout << "sum of row " << i << ": " << array[i][0] << endl;
    }
    return 0;
}