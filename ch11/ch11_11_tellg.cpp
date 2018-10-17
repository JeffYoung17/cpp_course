/*
 * 用 tellg函数 返回当前文件的指针所在的位置
 * 实现找到特定元素的位置
**/

#include <iostream>
#include <fstream>

using namespace std;

int main( int argc, char** argv )
{
    ifstream input( "./integer", ios_base::binary );
    if( input )
    {
        while( input )
        {
            streampos here = input.tellg();
            int temp;
            input.read( reinterpret_cast<char *>(&temp), sizeof(int) );
            if( input && temp == 0 )
            cout << " int O's position is " << here << endl;
        }
    }
    else
    {
        cout << "ERROR, No such file!" << endl;
    }
    input.close();

    return 0;
}