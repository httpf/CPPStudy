#include <string>
#include <iostream>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()): //参数默认值为空串
        ps(new std::string(s)), i(0){}

    HasPtr(const HasPtr&);

    HasPtr& operator=(const HasPtr&);

    friend void swap(HasPtr&, HasPtr&);

    ~HasPtr()
    {
        delete ps;
    }

private:
    std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr& source):
    i(source.i), ps(source.ps)
{
}

HasPtr& HasPtr::operator=(const HasPtr& orig)
{
    delete ps;
    i = orig.i;
    std::string *tempst = new std::string(*orig.ps);
    ps = tempst;
    return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "void swap" << std::endl;
}

int main(void)
{
    HasPtr h1("yao");
    HasPtr h2("xiang");
    swap(h1, h2);

    return 0;
}