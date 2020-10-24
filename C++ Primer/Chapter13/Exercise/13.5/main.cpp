#include <string>
#include <iostream>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) {}

    HasPtr(const HasPtr&);

private:
    std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr& source):
    i(source.i), ps(new std::string(*source.ps))
{
    std::cout << "copy constructor: ps=" << *ps << std::endl;;
}