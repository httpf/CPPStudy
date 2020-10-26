#include "Decorator.h"

string Mocha::getDescription()
{
    return pBeverage->getDescription() + ", add Mocha";
}

double Mocha::cost()
{
    return 0.2 + pBeverage->cost();
}

Mocha::~Mocha()
{
    
}