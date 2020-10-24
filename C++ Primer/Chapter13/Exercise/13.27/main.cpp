#include <string>
#include <iostream>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()): //参数默认值为空串
        ps(new std::string(s)), i(0), use(new std::size_t(1)){}

    HasPtr(const HasPtr&);

    HasPtr& operator=(const HasPtr&);

    ~HasPtr()
    {
        if(--*use == 0)
        {
            delete ps;
            delete use;
        }
    }

private:
    std::string *ps;
    int i;
    std::size_t *use;
};

HasPtr::HasPtr(const HasPtr& source):
    i(source.i), ps(source.ps), use(source.use)
{
    ++*use;
}

HasPtr& HasPtr::operator=(const HasPtr& orig)
{
    ++*orig.use;
    if(--*use == 0)
    {
        delete use;
        delete ps;
    }
    i = orig.i;
    ps = orig.ps;
    use = orig.use;
    return *this;
}