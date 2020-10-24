#include <iostream>
#include <string>
#include "Beverage.h"

using namespace std;

class CondimentDecorator : public Beverage
{
public:
    virtual string getDescription() = 0;
};