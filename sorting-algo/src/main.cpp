//
// Created by sajith on 12/20/21.
//

#include "sortings.h"

using std::cout;

#include <bitset>

int main()
{

    vector<int> arr{2, 7, 4, 1, 5, 3, 8, 6};
//    SelectionSort(arr);
//    BubbleSort(arr);
//    InsertionSort(arr);

//    MergeSort(arr);
    QuickSort(arr, 0, arr.size() - 1);
    for (auto &i: arr)
    {
        cout << i << '\t';
    }

    cout << '\n';


    return 0;
}