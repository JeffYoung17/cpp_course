/*
 * 以二进制模式向文件进行输出
 * 那么输出的结果就是一个二进制文件
**/

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
    // ios_base::binary是ios_base中的静态常量，访问的时候需要加上限定符
    ofstream file( "./data.dat", ios_base::binary );
    
    // 然后往文件里面写数据，第一个参数是字符类型的地址，第二个参数是大小
    file.write( reinterpret_cast<char *>(&dt), sizeof(dt) );
    return 0;
}