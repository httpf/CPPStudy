#include <iostream>

using namespace std;

int main()
{
    int i = 1, sum = 0;

    for(int i = 0; i< 100; ++i)
        sum += i;
    
    cout << i << " " << sum << endl;  // i = 1, sum = 4950
}