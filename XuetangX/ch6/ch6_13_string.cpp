#include <iostream>
#include <string>

using namespace std;

int main(int argc, char**argv)
{
    const char* const p = "test";
    cout << *(p + 1) << endl;
    cout << *(p + 4) << endl;

    string city,country;
    getline(cin, city, ',');
    getline(cin, country);
    cout << "City,Country: " << city << "," << country << endl;
    return 0;
}