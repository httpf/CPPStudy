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
}