#include <iostream>
#include <set>
#include <vector>
#include <memory>
#include "StrVec.h"

class QueryResult
{
friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    using line_no = StrVec::size_type;
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<StrVec> f):
        sought(s), lines(p), file(f){}

private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<StrVec> file;
};