#include <iostream>

using namespace std;

int main()
{
    unsigned int unint = -1;
    printf("unint = %u\n", unint); // unint = 4294967295

    unsigned char unchar = unint;
    printf("unchar = %u\n", unchar); // unchar = 255

    char ch = unint;
    printf("ch = %d\n", ch); // -1

    signed char c2 = 255;
    cout << c2 << endl;        // -1

    unsigned char c1 = -1;
    printf("%u\n", c1);    //255
    cout << endl;

    unsigned u1 = -10;
    int i1 = 42;
    cout << u1 + i1  << endl;    // 32

    unsigned u2 = 10;
    int i2 = -42; // 原码：1（25个0）101010 ，反码：（26个1）010101， 补码：（26个1）010110
    cout << u2 + i2 << endl;//(26个1)010110 转化为无符号整数。 （32个1）- （26个1）010110 =111111 - 010110 = 63 - 22 = 41
                            //(int)-42 转化为 unsigned, 结果为（32个1）- 41 = 2 的32次方 - 1 -41 
                            //= 2的32次方-42 
                            //= unsigned的模-42
                            //4294967254

    unsigned u3 = -42;
    cout << u3 << endl; //= unsigned的模-42
                        //4294967254

    unsigned u4 = 42, u5 = 10;

    cout << u4 - u5 << endl;

    cout << u5 - u4 << endl; // unsigned的模-32

    int s = -1;
    unsigned  un = 2;

    cout << s * un << endl;

    return 0;
}