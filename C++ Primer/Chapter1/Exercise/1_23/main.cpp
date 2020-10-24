#include <iostream>
#include "../../Common/Sales_item.h"

int main()
{
    int count = 0;
    Sales_item item;
    std::string curr_isbn;

    std::cin >> item;
    curr_isbn = item.isbn;

    if (curr_isbn.empty())
    {
        std::cerr << "Input error!" << std::endl;
        return -1;
    }
    else
    {
        ++count;
    }

    while (std::cin >> item)
    {
        if (item.isbn.empty())
        {
            std::cerr << "Input error!" << std::endl;
            break;
        }

        if (curr_isbn != item.isbn)
        {
            std::cout << curr_isbn << " has " << count << " records!" << std::endl;
            curr_isbn = item.isbn;
            count = 1;
        }
        else
        {
            ++count;
        }
    }

    std::cout << curr_isbn << " has " << count << " records!" << std::endl;

    return 0;
}