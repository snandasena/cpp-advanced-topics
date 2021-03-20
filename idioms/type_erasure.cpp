//
// Created by sajith on 3/16/21.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

namespace example
    {

            // 1. Type erasure using void* (like in C)
            void qsort(void *base, size_t num, size_t size, int(*compar)(const void *, const void *));

            int compare(const void *a, const void *b)
            {
                const int arg1 = *static_cast<const int *>(a);
                const int arg2 = *static_cast<const int *>(b);

                if (arg1 < arg2) return -1;
                if (arg1 > arg2) return 1;
                return 0;
            }

            // Drawback: not safe

            //2. Type erasure using template
            template<class RandomAccessIterator>
            void sort(RandomAccessIterator first, RandomAccessIterator last);

            // Drawback:
    }


int main()
{

    std::vector<int> v = {3, 1, 2};
//    std::vector<double > v = {33, 11, 22};
    std::qsort(v.data(), v.size(), sizeof(int), &example::compare);


    for (auto &i: v)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";


    std::vector<int> v2 = {3, 2, 1};
    std::sort(v2.begin(), v2.end());
    for (auto &i: v2)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}