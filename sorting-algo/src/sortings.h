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

void InsertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); ++i)
    {
        int val = arr[i];
        int hole = i - 1;
        while (hole >= 0 && arr[hole] > val)
        {
            arr[hole + 1] = arr[hole];
            hole -= 1;
        }
        arr[hole + 1] = val;
    }
}

void MergeSort(vector<int> &L, vector<int> &R, vector<int> &A)
{
    auto nL = L.size();
    auto nR = R.size();
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            ++i;
        }
        else
        {
            A[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < nL)
    {
        A[k] = L[i];
        ++i;
        ++k;
    }

    while (j < nR)
    {
        A[k] = R[j];
        ++j;
        ++k;
    }
}


void MergeSort(vector<int> &A)
{
    auto n = A.size();
    if (n < 2) return;

    auto mid = n / 2;
    vector<int> L(mid);
    vector<int> R(n - mid);

    for (int i = 0; i < mid; ++i)
    {
        L[i] = A[i];
    }

    for (int i = 0; i < n - mid; ++i)
    {
        R[i] = A[mid + i];
    }

    MergeSort(L);
    MergeSort(R);
    MergeSort(L, R, A);
}

int Partition(vector<int> &A, int start, int end)
{
    int pivot = A[end];
    int pIndex = start;
    for (int i = start; i < end; ++i)
    {
        if (A[i] <= pivot)
        {
            swap_elements(A[i], A[pIndex]);
            pIndex += 1;
        }
    }
    swap_elements(A[pIndex], A[end]);
    return pIndex;
}

void QuickSort(vector<int> &A, int start, int end)
{
    if (start < end)
    {
        int pIndex = Partition(A, start, end);
        QuickSort(A, start, pIndex - 1);
        QuickSort(A, pIndex + 1, end);
    }
}