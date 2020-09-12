#include <string>
#include <iostream>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()): //参数默认值为空串
        ps(new std::string(s)), i(0) {}

    HasPtr& operator=(const HasPtr&);

    HasPtr(const HasPtr&);

    ~HasPtr()
    {
        delete ps;
    }

private:
    std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr& source):
    i(source.i), ps(new std::string(*source.ps))
{
    std::cout << "copy constructor: ps=" << *ps << std::endl;;
}

HasPtr& HasPtr::operator=(const HasPtr& orig)
{
    i = orig.i;
    //*ps = *orig.ps;
    std::string *new_ps = new std::string(*orig.ps);
    delete ps;
    ps = new_ps;
    return *this;
}