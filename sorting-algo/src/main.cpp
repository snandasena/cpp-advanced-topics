//
// Created by sajith on 12/20/21.
//

#include "sortings.h"

using std::cout;

int main()
{

    vector<int> arr{2, 7, 4, 1, 5, 3};
//    SelectionSort(arr);
    BubbleSort(arr);
    for (auto &i: arr)
    {
        cout << i << '\t';
    }

    cout << '\n';

    return 0;
}