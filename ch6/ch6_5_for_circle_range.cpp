#include <iostream>
using namespace std;


int main(int argc, char** argv)
{
    int arr[3] = {1, 2, 3};
    for(auto & element_in_arr : arr)
    {
        element_in_arr += 1;
        cout << element_in_arr << endl;
    }
    return 0;
}

