//
// Created by sajith on 5/22/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
//    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
//    {
//        for (auto i: nums2)
//        {
//            nums1.emplace_back(i);
//        }
//
//        sort(nums1.begin(), nums1.end());
//
//        int l = nums1.size();
//        if (l % 2 == 0)
//        {
//            --l;
//            int x = nums1[l / 2];
//            int y = nums1[l / 2 + 1];
//            int z = x + y;
//            return (z * 1.0) / 2.0;
//        }
//
//        return nums1[l / 2] * 1.0;
//    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int l = nums1.size() + nums2.size();
        vector<int> merged(l);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());

        if (l % 2 == 0)
        {
            return ((merged[l / 2] + merged[l / 2 - 1])) * 1.0 / 2.0;
        } else
        {
            return merged[l / 2] * 1.0;
        }
    }
};


int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2);
    return 0;
}