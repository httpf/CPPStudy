#include "Decorator.h"

Mocha::Mocha(Beverage *p)
{
    pBeverage = p;
}

string Mocha::getDescription()
{
    return pBeverage->getDescription() + ", Mocha";
}

double Mocha::cost()
{
    return 0.2 + pBeverage->cost();
}

Mocha::~Mocha()
{
    
}