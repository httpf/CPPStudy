#ifndef DECORATOR_H
#define DECORATOR_H
#include <iostream>
#include <string>
#include "Beverage.h"

using namespace std;

class CondimentDecorator : public Beverage
{
public:
    CondimentDecorator(Beverage *pBev) : pBeverage(pBev) {}

protected:
    Beverage *pBeverage;
};

class Mocha : public CondimentDecorator
{
public:
    Mocha(Beverage *p) : CondimentDecorator(p) {};
    string getDescription();
    double cost();
    ~Mocha();
};
#endif