#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
    /*
    C++20标准，@see literals(字面量)
    */

    //十进制整数字面量
    cout << sizeof(int) << endl << sizeof(long) << endl << sizeof(long long) << endl; //4 4 8
    cout << sizeof(128) << endl; //4, 当成int类型
    cout << sizeof(85899345921111) << endl; //8, 当成long long类型
    cout << sizeof(128LL) << endl;  //8, 当成long long类型
    cout << "------1------" << endl;

    /*
    C++20标准
        signed char    符号位  >=8bit  可表示的数值范围[-2^(N-1), 2^(N-1) - 1]
      unsigned char  无符号位  >=8bit  可表示的数值范围[0, 2^N - 1]
            1.unsigned char 与 signed char有相同的存储大小, 具体大小由 implementation define
            2.unsigned char has the same object representation, value representation, and alignment requirements as signed char
                eg: N=8
                signed char     -128             -1         0                127
                              1000 0000, ..., 1111 1111, 0000 0000, ..., 0111 1111
              unsigned char     128              255        0                127 
            3.char是独立的类型，implementation choose signed char或者unsigned char作为其underlying type
              char 和其 underlying type has the same object representation, value representation, and alignment requirements as signed char

    */


    //x86_64-ucrt-posix-seh 的 gcc 编译器
    
    //char, signed char, unsigned char 存储大小为 1个字节
    cout << sizeof(char) << endl; //1

    char c = 128; //字面量128(当成int类型): 0000 ... 1000 0000，截断成一个字节 1000 0000 存储
    signed char sc = 128;
    unsigned char usc = 128;

    //相同的value representation
    cout << hex << (c & 0xff) << endl; //80
    cout << hex << (sc & 0xff) << endl; //80
    cout << hex << (usc & 0xff) << endl; //80

    cout << dec;
    cout << (int)c << endl;  //-128
    cout << (int)sc << endl; //-128 , signed 补1
    cout << (int)usc << endl; //128 , unsigned 补0

    //char choose signed char
    cout << (c == usc) << endl;  //0
    cout << (c == sc) << endl;   //1
    cout << (sc == usc) << endl; //0

    cout << "------2------" << endl;

    //execution character set:
    //gcc and clang use -finput-charset to specify the encoding of the source character set, -fexec-charset and -fwide-exec-charset to specify the encodings of the execution character set in the string and character literals that don't have an encoding prefix (since C++11),
    //while Visual Studio 2015 Update 2 and later uses /source-charset and /execution-charset to specify the source character set and execution character set respectively
    
    //字符字面量a, 当成char类型, 存储 按照execution character set 将字符a编码输出的字节
    //如果字符a在execution character set 中不能表示，is conditionally-supported, has type int, and has an implementation-defined value
    char cr = 'a'; //gcc编译器中默认的 execution character set 为 UTF-8
    cout << cr << endl;  //a
    cout << (int)cr << endl; //97

    //字符字面量‘中’，按照UTF-8编码为 0xe4b8ad，三个字节，而此处char仅一个字节，编译警告而未报错，截断成 ad
    cr = '中';
    cout << cr << endl; //�
    cout << hex << (cr & 0xff) << endl; //ad

    //字符串字面量”h中“, 当成 array of n const char with end \0, 按照execution character set编码成字节串
    char crs[] = "h中𝕆"; // h 按UTF-8编码 0x68，中 按UTF-8编码 0xe4b8ad，此处一个char一个字节
    cout << strlen(crs) << endl; //8
    //将字节序列0x68 e4b8ad传送给terminal，需要terminal采用UTF-8编码，才能正确解析该字节序列
    cout << crs << endl; //h中𝕆
    
    
}
