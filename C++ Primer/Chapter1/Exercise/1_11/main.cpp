#include <iostream>

int main()
{
    int a = 0, b = 0;
    std::cout << "Please input two integer:" << std::endl;

    std::cin >> a >> b;

    if(a >= b)
    {
        while(a>=b)
        {
            std::cout <<a << " ";
            --a;
        }
    }
    else
    {
        while(b>=a)
        {
            std::cout <<b << " ";
            --b;
        }
    }

    std::cout << std::endl;

    return 0;
}