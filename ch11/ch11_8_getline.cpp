/*
 * 使用getline函数输入
**/

#include <iostream>
#include <string>

using namespace std;

int main( int argc, char** argv )
{
    string line;
    cout << "please input by end 't' " << endl;
    
    // 不指定终止符的话，getline默认以换行符作为终止符
    getline( cin, line, 't');
    
    cout << line << endl;
    return 0;
}