//
// Created by sajith on 12/20/21.
//

#include <bits/stdc++.h>

using std::vector;

void swap_elements(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr[i] > arr[j])
            {
                swap_elements(arr[i], arr[j]);
            }
        }
    }
}


void BubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr.size() - 2; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap_elements(arr[j], arr[j + 1]);
            }
        }
    }
}