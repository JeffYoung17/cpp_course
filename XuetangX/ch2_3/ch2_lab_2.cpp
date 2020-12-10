#include <iostream>
using namespace std;

double power (double x, int n); //计算x的n次方

int main() {
    int value = 0;
    int bin_num = 0;
    int arr[10] = {0};
    cin >> bin_num;
    for (int i = 0; i < 10; i++) {
        arr[i] = bin_num / static_cast<int>(power(10,i)) % 10;
        if(arr[i] == 1) {
            value += static_cast<int>(power(2,i));
        }
    }
    cout << value << endl;
    return 0;
}
double power (double x, int n) {
    double val = 1.0;
    while (n--) 
      val *= x;
    return val;
}