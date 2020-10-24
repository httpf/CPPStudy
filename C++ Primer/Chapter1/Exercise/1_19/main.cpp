#include <iostream>

int main()
{
    int val1, val2, temp;
    std::cout << "Please input two integers: "; 
    std::cin >> val1 >> val2;

    if(val1 <= val2)
        while(val1 <= val2)
        {
            std::cout << val1 << " ";
            ++val1;
        }

    else
        while(val2 <= val1)
        {
            std::cout << val1 << " ";
            --val1;
        }

    std::cout << std::endl;

    return 0;
}