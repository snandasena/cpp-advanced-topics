//
// Created by sajith on 12/24/21.
//

#ifndef ADVANCED_TOPICS_BIN_SEARCH_H
#define ADVANCED_TOPICS_BIN_SEARCH_H

#include <bits/stdc++.h>

using std::vector;

int BinarySearchIterative(vector<int> &arr, int x)
{
    int end = static_cast<int>(arr.size() - 1);
    int start = 0;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == x) return mid;
        else if (x < arr[mid]) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int BinarySearchRecursive(vector<int> &arr, int start, int end, int x)
{
    if (start == end) return -1;
    int mid = start + (end - start) / 2;

    if (arr[mid] == x) return mid;
    else if (x < arr[mid]) return BinarySearchRecursive(arr, start, mid - 1, x);
    else return BinarySearchRecursive(arr, mid + 1, end, x);
}

int BinarySearchFindFirstOrLastOccurrence(vector<int> &arr, int x, bool first = true)
{
    auto end = static_cast<int>(arr.size() - 1);
    int start = 0;
    int res = -1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == x)
        {
            if (first)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            res = mid;
        }
        else if (x < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}

#endif //ADVANCED_TOPICS_BIN_SEARCH_H
