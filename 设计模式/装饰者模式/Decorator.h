#ifndef DECORATOR_H
#define DECORATOR_H
#include <iostream>
#include <string>
#include "Beverage.h"

using namespace std;

class CondimentDecorator : public Beverage
{
public:
    virtual string getDescription() = 0;
};

class Mocha : public CondimentDecorator
{
protected:
    Beverage *pBeverage;

public:
    Mocha(Beverage *p);
    string getDescription();
    double cost();
    ~Mocha();
};
#endif