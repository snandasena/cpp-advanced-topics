//
// Created by sajith on 6/24/21.
//

#include <iostream>
#include <vector>

using namespace std;


int getVal()
{
    return 10;
}


int add(int a, int b)
{
    return a + b;
}

bool ascendingComp(int a, int b)
{
    return a > b;
}

bool descendingComp(int a, int b)
{
    return a < b;
}

void customSort(vector<int> &nums, bool (*compareFuncPtr)(int, int))
{
    for (int i = 0; i < nums.size(); ++i)
    {
        int bestIndx = i;
        for (int j = bestIndx + 1; j < nums.size(); ++j)
        {
            if (compareFuncPtr(nums[bestIndx], nums[j]))
            {
                bestIndx = j;
            }
        }
        swap(nums[bestIndx], nums[i]);
    }
}

int main()
{
    cout << getVal << endl;

    int (*fp)() = getVal;
    cout << fp() << endl;

    int (*addFunPtr)(int, int) = add;
    cout << addFunPtr(10, 20) << endl;

    vector<int> nums = {1, 4, 2, 5, 10, 6};
    customSort(nums, ascendingComp);

    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    nums.clear();
    nums = {1, 4, 2, 5, 10, 6};

    customSort(nums, descendingComp);

    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}