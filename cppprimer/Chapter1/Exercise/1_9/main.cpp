#include <iostream>

int main()
{
    int i = 50;
    int sum = 0;
    while(i<=100)
        sum += i++;

    std::cout << "sum = " << sum << std::endl;

    return 0;
}