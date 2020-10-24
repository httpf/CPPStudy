#include <iostream>
#include <string>
#include "Beverage.h"

using namespace std;

class Espresso : public Beverage
{
public:
    Espresso()
    {
        description = "Espresso";
    }

    double cost()
    {
        return 1.99;
    }
};

class HouseBlend : public Beverage
{
public:
    HouseBlend()
    {
        description = "House Blend Coffee";
    }
    double cost()
    {
        return 0.89;
    }
};

class DarkRoast : public Beverage
{
public:
    DarkRoast()
    {
        description = "Dark Roast Coffee";
    }
    double cost()
    {
        return 1.20;
    }
};

class Decat : public Beverage
{
public:
    Decat()
    {
        description = "Decat";
    }
    double cost()
    {
        return 1.9;
    }
};