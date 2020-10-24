#include "StrVec.h"


void StrVec::push_back(const std::string& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e-b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if(elements)
    {
        for(auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::allocate_tool(std::size_t n)
{
    auto newcapacity = n;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem= elements;
    for(size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2*size() : 1;
    allocate_tool(newcapacity);
}

void StrVec::reserve(std::size_t n)
{
    if(capacity() < n)
    {
        allocate_tool(n);
    }
}

void StrVec::resize(std::size_t n)
{

}

void StrVec::resize(std::size_t n, std::string &s)
{
    if(size() > n)
        while(first_free != elements+n) alloc.destroy(--first_free);
    else if(size() < n)
    {
        if(n > capacity())
            reserve(n * 2);
        for(int i = size(); i != n; ++i)
            alloc.construct(first_free++, s);
    }
    
}