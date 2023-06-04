//
// Created by sajith on 10/7/22.
//

#include <iostream>
#include <algorithm>
#include <execution>
#include <numeric>
#include <vector>
#include <string>

using std::cout;
#define endl  '\n'

double calc_average_serial(const std::vector<int> &nums)
{
    return std::accumulate(nums.cbegin(), nums.cend(), 0) / (double) nums.size();
}

double calc_average_parallel(const std::vector<int> &nums)
{
    return std::reduce(std::execution::par, nums.cbegin(), nums.cend(), 0) / (double) nums.size();
}

int calc_product_serial(const std::vector<int> &nums)
{
    return std::accumulate(nums.cbegin(), nums.cend(), 1, std::multiplies());
}

int calc_product_parallel(const std::vector<int> &nums)
{
    return std::reduce(std::execution::par, nums.cbegin(), nums.cend(), 1, std::multiplies());
}

int count_new_lines_binary_func(int prev, char c)
{
    if (c == '\n')
        return prev + 1;
    return prev;
}

int count_new_lines(const std::string &str)
{
    return std::accumulate(str.cbegin(), str.cend(), 0, count_new_lines_binary_func);
}


int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    cout << calc_average_serial(v) << endl;
    cout << calc_average_parallel(v) << endl;
    cout << calc_product_serial(v) << endl;
    cout << calc_product_parallel(v) << endl;

    std::string str{"hello world\ntest line two\ntest line three."};
    cout << count_new_lines(str) << endl;
    return 0;
}