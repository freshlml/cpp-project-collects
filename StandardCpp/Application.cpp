#include<iostream>
#include<limits.h>
#include<cstring>

using namespace std;

int main()
{
    //环境: x86_64-redhat-linux-posix gcc version 9.3.1 20200408


    //int类型: 4 字节，它的最大正数: 2147483647 ( 2^31 - 1 ). signed.
    cout << "int类型: " << sizeof(int) << " 字节，它的最大值: " << INT_MAX << " ( 2^" << (sizeof(int)*8-1) << " - 1 )" << endl;

    //long类型: 8 字节，它的最大正数: 9223372036854775807 ( 2^63 - 1 ). signed.
    cout << "long类型: " << sizeof(long) << " 字节，它的最大值: " << LONG_MAX << " ( 2^" << (sizeof(long)*8-1) << " - 1 )" << endl;

    //char类型: 1 字节，它的最大值: 127 ( 2^7 - 1 ). signed
    cout << "char类型: " << sizeof(char) << " 字节，它的最大值: " << CHAR_MAX << " ( 2^" << (sizeof(char)*8-1) << " - 1 )" << endl;
    /*  unsigned char has the same object representation, value representation, and alignment requirements as signed char
              signed char       -128             -1         0                127
                              1000 0000, ..., 1111 1111, 0000 0000, ..., 0111 1111
              unsigned char     128              255        0                127 
    */
    

    char c = 128;            //整数字面量128当成int类型: 0000 0000 ... 1000 0000，截断成一个字节: 1000 0000
    cout << (int)c << hex << " 0x" << (c & 0xff) << dec << endl;  //-128 0x80

    signed char sc = 128;    //整数字面量128当成int类型: 0000 0000 ... 1000 0000，截断成一个字节: 1000 0000
    cout << (int)sc << hex << " 0x" << (sc & 0xff) << dec << endl;  //-128 0x80

    unsigned char usc = 128; //整数字面量128当成int类型: 0000 0000 ... 1000 0000，截断成一个字节: 1000 0000
    cout << (int)usc << hex << " 0x" << (usc & 0xff) << dec << endl;  //128 0x80


    //execution character set: gcc and clang use -finput-charset to specify the encoding of the source character set, 
    //                         -fexec-charset and -fwide-exec-charset to specify the encodings of the execution character set 
    //                         in the string and character literals that don't have an encoding prefix (since C++11),
    //                         while Visual Studio 2015 Update 2 and later uses /source-charset and /execution-charset to 
    //                         specify the source character set and execution character set respectively.
    
    //gcc编译器中 execution character set 默认值为 UTF-8

    char cr = 'h';   //字符字面量'a'被当成char类型：使用 execution character set 编码，'h' 按照 UTF-8 编码为 0x68

    //字符串字面量"h中𝕆", 当成 array of n const char with end \0, 按照 execution character set 编码成字节串
    char crs[] = "h中𝕆"; // 'h'按UTF-8编码为 0x68，'中'按UTF-8编码为 0xe4b8ad，'𝕆'按UTF-8编码为 0xf09d9586
    cout << strlen(crs) << " " << crs << endl;  //8 h中𝕆

}
