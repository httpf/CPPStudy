#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    vector<int> ivec = {5, 4, 2};
    int num = 100;
    std::modulus<int> mod;
    auto is_divisible = std::all_of(ivec.begin(), ivec.end(),
                               [&mod, &num](int i) -> bool {
                                   cout << "mod(" << num << ", " << i << ") = " << (bool)mod(num, i) << endl;

                                   if (mod(num, i))
                                       return false;
                                   else
                                       return true;
                               });
    cout << is_divisible << endl;
}