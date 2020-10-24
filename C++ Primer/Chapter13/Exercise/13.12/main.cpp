#include <iostream>

struct X {
    X() {std::cout << "X()" << std::endl;}
    X(const X&)
    {
        std::cout << "X(const X&)" << std::endl;
    }
    X& operator=(const X&)
    {
        std::cout << "X& operator=(const X&)" << std::endl;
        return *this;
    }
    ~X()
    {
        std::cout << "~X()" << std::endl;
    }
};

void f(X temp)
{
    std::cout << "void f(X temp)" << std::endl;
}

X f2(X &temp)
{
    return temp;
}

int main(void)
{
    X x1;
    X x2;
    x2 = x1;
    // f(x1);
    // f2(x1);

/*
程序输出如下：
X()
X(const X&)
void f(X temp)
~X()
X(const X&)
~X()
~X()
*/
}