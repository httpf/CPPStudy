#include <string>

using namespace std;

class Beverage
{
protected:
    string description = "Unknown Beverage";

public:
    string getDescription()
    {
        return description;
    }

    virtual double cost() = 0;
};