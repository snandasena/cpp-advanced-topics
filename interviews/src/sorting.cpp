//
// Created by sajith on 5/25/22.
//

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;


/*
 * Time complexity  : Best case O(n)
 *                  : Worst case O(n^2)
 *                  : Average case O(n^2)
 */

void BubbleSort(vector<int> &v)
{
    bool canStop;
    auto N = v.size();

    for (auto i = 0; i < N - 1; ++i)
    {
        canStop = true;
        for (auto j = 0; j < N - i - 1; ++j)
        {
            if (v[j] > v[j + 1])
            {
                std::swap(v[j], v[j + 1]);
                canStop = false;
            }
        }

        if (canStop)break;
    }
}

void PrintArray(const vector<int> &v)
{
    for (const auto &ele: v)
    {
        printf("%d\t", ele);
    }
    printf("\n");
}

void BubbleSortTest()
{
    vector<int> v{23, 12, 43, 12, 22, 11, 43, 65, 7, 98, 2, 3, 100, 50};
    BubbleSort(v);
    PrintArray(v);
}

/*
 * Time complexity  : Best case O(n^2)
 *                  : Worst case O(n^2)
 *                  : Average case O(n^2)
 */
void SelectionSort(vector<int> &v)
{
    size_t minIndx;
    auto N = v.size();

    for (auto i = 0; i < N - 1; ++i)
    {
        minIndx = i;
        for (auto j = i + 1; j < N; ++j)
        {
            if (v[j] < v[minIndx])
            {
                minIndx = j;
            }
        }

        std::swap(v[i], v[minIndx]);
    }
}
void SelectionSortTest()
{
    vector<int> v{23, 12, 43, 12, 22, 11, 43, 65, 7, 98, 2, 3, 100, 50};
    SelectionSort(v);
    PrintArray(v);
}


int main()
{
    BubbleSortTest();
    SelectionSortTest();
}