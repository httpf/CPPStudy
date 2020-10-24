#include <iostream>

#include "../../Common/Sales_item.h"

int main()
{
    //读写Sales_item
    // Sales_item book;
    // std::cin >> book;
    // std::cout << book << std::endl;

    //Sales_item对象的加法
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    std::cout << item1 + item2 << std::endl;

    
    return 0;
}