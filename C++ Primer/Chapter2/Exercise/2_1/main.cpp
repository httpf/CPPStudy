#include <iostream>

using namespace std;

int main()
{
    cout << "Windows 7 (x64)" << endl;
    cout << "---------------------------------" << endl;
    cout << "sizeof(bool) = " << sizeof(bool) << endl;
    cout << "sizeof(char) = " << sizeof(char) << endl;
    cout << "sizeof(short) = " << sizeof(short) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << "sizeof(long long) = " << sizeof(long long) << endl;
    cout << "---------------------------------" << endl;
    cout << "sizeof(float) = " << sizeof(float) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(long double) = " << sizeof(long double) << endl;
    cout << "---------------------------------" << endl;
    cout << "sizeof(unsigned char) = " << sizeof(unsigned char) << endl;
    cout << "sizeof(unsigned) = " << sizeof(unsigned) << endl;

    /*
    Windows 7 (x64)
    ---------------------------------
    sizeof(bool) = 1
    sizeof(char) = 1
    sizeof(short) = 2
    sizeof(int) = 4
    sizeof(long) = 4
    sizeof(long long) = 8
    ---------------------------------
    sizeof(float) = 4
    sizeof(double) = 8
    sizeof(long double) = 12
    ---------------------------------
    sizeof(unsigned char) = 1
    sizeof(unsigned) = 4
    */
}