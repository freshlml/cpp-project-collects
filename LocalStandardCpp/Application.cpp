#include<iostream>
#include<limits.h>

using namespace std;

int main()
{
    //环境: x86_64-w64-mingw32-posix gcc version 12.2.0

    //int类型: 4 字节，它的最大值: 2147483647 ( 2^31 - 1 ). signed.
    cout << "int类型: " << sizeof(int) << " 字节，它的最大值: " << INT_MAX << " ( 2^" << (sizeof(int)*8-1) << " - 1 )" << endl;

    //long类型: 4 字节，它的最大值: 2147483647 ( 2^31 - 1 ). signed.
    cout << "long类型: " << sizeof(long) << " 字节，它的最大值: " << LONG_MAX << " ( 2^" << (sizeof(long)*8-1) << " - 1 )" << endl;

    //char类型: 1 字节，它的最大值: 127 ( 2^7 - 1 ). signed
    cout << "char类型: " << sizeof(char) << " 字节，它的最大值: " << CHAR_MAX << " ( 2^" << (sizeof(char)*8-1) << " - 1 )" << endl;


}