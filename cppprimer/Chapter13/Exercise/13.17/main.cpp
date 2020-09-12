#include <iostream>

class numbered
{
public:
    int mysn;
    static int unique;
public:
    numbered();
    numbered(const numbered& orig)
    {
        mysn = orig.mysn+ 10;
        std::cout << "numbered(const numbered& orig) mysn=" << mysn << std::endl;
    }
    numbered& operator=(const numbered &orig)
    {
        mysn = orig.mysn+ 10;
        std::cout << "numbered& numbered::operator=(const numbered &orig) mysn=" << mysn << std::endl;
        return *this;
    }
    ~numbered();
};

int numbered::unique = 10;

numbered::numbered()
{
    unique++;
    mysn = unique;
    std::cout << "numbered::numbered() mysn=" << mysn << std::endl;
}

void f (numbered s)
{ 
    std::cout << "void f (numbered s) s.mysn = " << s.mysn << std::endl;
}

numbered::~numbered()
{
}

int  main(void)
{
    numbered a;
    // numbered b = a;
    // numbered c = b;

    f(a); //以值传递的方式将类类型的对象传递给函数的形参数--拷贝构造函数
    return 0;
}
