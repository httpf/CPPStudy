#ifndef STRING_H_YX
#define STRING_H_YX
#include <algorithm>
#include <memory>

class String
{
private:
    std::allocator<char> alloc;
    char *elements;
    char *end;
public:
    String();
    String(const char *chr);
    std::pair<char*, char*> alloc_n_copy(const char *b, const char *e);
    ~String();
};

String::String()
{
    elements = end = nullptr;
}

std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
    auto data = alloc.allocate(e-b);
    return {data, std::uninitialized_copy(b, e, data)};
}

String::String(const char *chr)
{
    auto s = const_cast<char*>(chr);
    while(*s) ++s;
    auto newdata = alloc_n_copy(chr, s);
    elements = newdata.first;
    end = newdata.second;
}

String::~String()
{
    if(elements)
    {
        std::for_each(elements, end, [this](char *rhs){alloc.destroy(&rhs);});
        alloc.deallocate(elements, end-elements);
    }

}

#endif
