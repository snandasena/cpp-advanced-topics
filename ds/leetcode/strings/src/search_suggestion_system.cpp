//
// Created by sajith on 6/19/22.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:

    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        sort(products.begin(), products.end());
        vector<vector<string>> res;

        int start;
        int bsStart = 0;
        auto n = static_cast<int>(products.size());
        string prefix;

        for (const char &c: searchWord)
        {
            prefix += c;
            start = lower_bound(products.begin() + bsStart, products.end(), prefix) - products.begin();
            res.emplace_back();

            for (int i = start; i < min(start + 3, n) && !products[i].compare(0, prefix.length(), prefix); ++i)
            {
                res.back().push_back(products[i]);
            }
            bsStart = start;
        }
        return res;
    }
};

bool operator<(const string &str1, const string &star2)
{
    return true;
}

int main()
{
    vector<char> v{'h', 'e', 'l', 'l', 'o'};
    char c{'l'};

    auto start = lower_bound(v.begin(), v.end(), c) - v.begin();
    cout<< start<<endl;
    return 0;
}