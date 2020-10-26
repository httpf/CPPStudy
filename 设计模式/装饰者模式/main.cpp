#include <iostream>
#include "Beverage.h"
#include "Decorator.h"

using namespace std;

int main()
{
    Beverage *pBeverage = new Espresso();
    cout << pBeverage->getDescription() << endl;

    HouseBlend *pBeverage2 = new HouseBlend();

    Beverage *pBeverage3 = new Mocha(pBeverage2);

    cout << pBeverage3->getDescription() << endl;

    return 0;
}