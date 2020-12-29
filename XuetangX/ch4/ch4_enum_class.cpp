#include <iostream>
#include <string>

using namespace std;

enum class Side : int {
    Left,
    Right
};

enum class Test : int {
    Left,
    Other
};

int main()
{
    Side side = Side::Left;
    Test test = Test::Left;
    return 0;
}