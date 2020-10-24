#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include "QueryResult.h"
#include "StrVec.h"

using namespace std;

class QueryResult;

class TextQuery
{
public:
    using line_no = StrVec::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
private:
    shared_ptr<StrVec> file;
    map<string, shared_ptr<set<line_no>>> wm;
};