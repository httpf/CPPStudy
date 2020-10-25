#include <iostream>
#include "Beverage.h"
#include "Decorator.h"

using namespace std;

int main()
{
    Beverage *pBeverage = new Espresso();
    cout << pBeverage->getDescription() << endl;

    Beverage *pBeverage2 = new HouseBlend();
    Beverage *pBeverage3 = new Mocha(pBeverage2);

    cout << pBeverage3->getDescription() << endl;

    delete pBeverage3;
    delete pBeverage2;
    delete pBeverage;

    return 0;
}