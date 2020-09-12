#ifndef STRVEC_H
#define STRVEC_H
#include <memory>
#include <string>
#include <utility>
#include <initializer_list>

class StrVec {
public:
    StrVec():
        elements(nullptr), first_free(nullptr), cap(nullptr){}
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);
    StrVec(std::initializer_list<std::string> lst);
    ~StrVec();
    void push_back(const std::string&);
    size_t size() const { return first_free - elements;}
    size_t capacity() const { return cap - elements;}
    std::string *begin() const { return elements;}
    std::string *end() const { return first_free;}
    void reserve(std::size_t n);
    void resize(std::size_t n);
    void resize(std::size_t n, const std::string &s);

    typedef size_t  size_type;

private:
    std::allocator<std::string> alloc;
    void chk_n_alloc() { if(size() == capacity()) reallocate();}
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();
    void allocate_tool(std::size_t n);
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};
#endif