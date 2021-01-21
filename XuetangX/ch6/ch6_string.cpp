#include <iostream>
#include <string>

using namespace std;

int main(int argc, char**argv)
{
    string city,country;
    
    getline(cin, city, ',');
    getline(cin, country, ',');

    cout << "City,Country: " << city << "," << country << endl;


    return 0;
}