//
// Created by sajith on 7/1/22.
//


#include <bits/stdc++.h>


using namespace std;

struct Compare
{

    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        return a[1] > b[1];
    }

};

class Solution
{
public:
    int maximumUnits2(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), Compare());

        int cuur = 1;
        int ans = 0;
        for (int i = 0; i < boxTypes.size(); ++i)
        {
            while (boxTypes[i][0] != 0 && cuur <= truckSize)
            {
                ans += boxTypes[i][1];
                --boxTypes[i][0];
                ++cuur;
            }
        }

        return ans;

    }

    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), Compare());

        int ans = 0;
        int mn;
        for (auto &boxType: boxTypes)
        {
            mn = min(truckSize, boxType[0]);
            ans += mn * boxType[1];
            truckSize -= mn;
        }
        return ans;
    }
};
