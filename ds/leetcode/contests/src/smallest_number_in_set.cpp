//
// Created by sajith on 7/10/22.
//

#include <bits/stdc++.h>

using namespace std;

class SmallestInfiniteSet
{
    vector<int> arr;
public:
    SmallestInfiniteSet()
    {
        arr.resize(1001, 1);

    }

    int popSmallest()
    {
        for (int i = 1; i <= 1000; ++i)
        {
            if (arr[i] != 0)
            {
                arr[i] = 0;
                return i;
            }
        }
        return -1;
    }

    void addBack(int num)
    {
        if (arr[num] == 0)
        {
            arr[num] = 1;
        }
    }
};


// [null, null, 1, 2, 3, null, 1, 4, 5]
// [null,null, 1, 2, 3,null, 1, 4, 5]

int main()
{
    SmallestInfiniteSet st;

    st.addBack(2);

}