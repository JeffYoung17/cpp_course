/*
 * 
**/

#include <iostream>
#include <fstream>

using namespace std;

struct Date{
    int mon, day, year;
};

int main( int argc, char** argv )
{
    Date dt = {
        .mon = 6,
        .day = 10,
        .year = 92
    };
    // 把输出流对象和当前工作目录下的名字叫做data.dat的文件联系起来
    ofstream file( "data.dat", ios_base::binary );
    // 然后往文件里面写数据，第一个参数是地址，第二个参数是大小
    file.write( reinterpret_cast<char *>(&dt), sizeof(dt) );
    return 0;
}