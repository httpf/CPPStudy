#include <iostream>

int main()
{
    std::cout << "Please input some integers:" << std::endl;
    int a = 0, sum = 0;
    while(std::cin >> a)
    {
        sum += a;
    }

    std::cout << "sum = " << sum << std::endl;
    return 0;
}