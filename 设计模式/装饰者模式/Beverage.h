#ifndef BEVERAGE_H
#define BEVERAGE_H
#include <string>
using namespace std;

class Beverage
{
protected:
    string description = "Unknown Beverage";

public:
    string getDescription();
    virtual double cost() = 0;
    virtual ~Beverage();
};

class Espresso : public Beverage
{
public:
    Espresso();
    double cost();
};

class HouseBlend : public Beverage
{
public:
    HouseBlend();
    double cost();
};

class DarkRoast : public Beverage
{
public:
    DarkRoast();
    double cost();
};
#endif