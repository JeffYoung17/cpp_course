/*
 * 先用二进制的方式写入到一个文件中
 * 然后用二进制的方式读取进来
**/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct SalaryInfo {
    unsigned id;
    double salary;
}; 

int main( int argc, char** argv )
{
    SalaryInfo employee1 = {
        .id = 21725199,
        .salary = 19873.2
    };

    // 把程序中的数据以二进制的方式输出到了文件当中
    ofstream out ( "./data", ios_base::binary );
    out.write( reinterpret_cast<char *>(&employee1), sizeof(employee1) );
    out.close();

    // 把文件读到文件输入流中，用二进制的方式；
    // 知道读取数据的格式，所以实例化对象来接收数据，用ifstream.read()
    ifstream input( "./data", ios_base::binary );
    if(input)
    {
        SalaryInfo employee2;
        input.read( reinterpret_cast<char *>(&employee2), sizeof(employee2) );
        cout << employee2.id << " " << employee2.salary << endl;
    }
    else
    {
        cout << "ERROR, No such file!" << endl;
    }
    input.close();

    return 0;
}