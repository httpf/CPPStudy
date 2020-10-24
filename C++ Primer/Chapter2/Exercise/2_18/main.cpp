#include <iostream>

using namespace std;

int main()
{
    int m = 5, n = 10, *pm = &m;

    pm = &n; // change the value of pointer

    *pm = 20;

    cout << "*pm = " << *pm << endl;
    return 0;
}