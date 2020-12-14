#include <iostream>
#include <functional>
#include <map>

using namespace std;

int add(int i, int j) { return i + j; };

auto mod = [](int i, int j) { return i % j; };

struct divide
{
    int operator()(int dividend, int divisor) { return dividend / divisor; }
};

map<string, function<int(int, int)>> binops = {
    {"+", add},
    {"-", std::minus<int>()},
    {"*", [](int i, int j) { return i * j; }},
    {"/", divide()},
    {"%", mod}};

int main(int argc, const char **argv)
{
    while (1)
    {
        cout << "Please input as 2 * 5 :" << endl;;
        int lhs, rhs;
        string op;
        cin >> lhs >> op >> rhs;
        cout << binops[op](lhs, rhs) << endl;
    }

    return 0;
}