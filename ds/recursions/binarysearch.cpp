//
// Created by sajith on 7/24/21.
//

#include <bits/stdc++.h>

using namespace std;


int binarysearch(vector<int> &vec, int left, int right, int x)
{
    if (left > right)
    {
        return -1;
    }

    int mid = (left + right) / 2;

    if (x == vec[mid])
    {
        return mid;
    }

    if (x < vec[mid])
    {
        return binarysearch(vec, left, mid - 1, x);
    }

    return binarysearch(vec, mid + 1, right, x);
}

int main()
{

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << binarysearch(v, 0,9, 5 ) << endl;

    return 0;
}