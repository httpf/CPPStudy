#include <iostream>

using namespace std;

int main()
{
    unsigned u = 10, u2 = 42;
    cout << "u2 - u = " << u2 - u << endl;
    cout << "u - u2 = " << u - u2 << endl; //对结果-32取模， 

    int i = 10, i2 = 42;
    cout << "i2 - i = " << i2 - i << endl;
    cout << "i - i2 = " << i - i2 << endl;
    cout << "i - u = " << i - u << endl;  //0在unsigned取值范围内
    cout << "u - i = " << u - i << endl;

    // u2 - u = 32
    // u - u2 = 4294967264
    // i2 - i = 32
    // i - i2 = -32
    // i - u = 0 
    // u - i = 0

    return 0;
}