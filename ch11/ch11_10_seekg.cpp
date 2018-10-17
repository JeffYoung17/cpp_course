/*
 * 用 seekg函数 移动文件指针的位置
 * 实现读取指定位置开始的数据
**/

#include <iostream>
#include <fstream>

using namespace std;

int main( int argc, char** argv )
{
    int values[] = {9, 1, 2, 4 ,3, 8};
    ofstream out( "./integer", ios_base::binary );
    out.write( reinterpret_cast<char *>(values), sizeof(values) );
    out.close();


    ifstream in( "./integer", ios_base::binary );
    if( in )
    {
        in.seekg( 3*sizeof(int) );
        int temp;
        in.read( reinterpret_cast<char *>(&temp), sizeof(int) );
        cout << "The 4th integer of values[] is " << temp << endl;
    }
    else
    {
        cout << "ERROR, No such file!" << endl;
    }

    return 0;
}