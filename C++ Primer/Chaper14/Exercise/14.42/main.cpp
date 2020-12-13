#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std::placeholders;
using namespace std;

int main(int argc, const char**argv)
{
    vector<int> ivec = {1, 11, 111, 1111, 11111};
    size_t counti = std::count_if(ivec.begin(), ivec.end(), bind(greater<int>(), _1, 1024));
    cout << counti << endl;

    vector<string> svec = {"pooch", "apple", "nanana", "pooch"};
    auto word = find_if(svec.begin(), svec.end(), bind(not_equal_to<string>(), _1, "pooth"));
    cout << *word << endl;

    transform(ivec.begin(), ivec.end(), ivec.begin(), bind(multiplies<int>(), _1, 2))

}