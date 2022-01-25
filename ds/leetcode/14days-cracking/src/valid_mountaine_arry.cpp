
//
// Created by sajith on 1/25/22.
//

#include "base.h"

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        auto N = static_cast<int>(arr.size());
        if (N == 3)
        {
            if (arr[0] < arr[1] && arr[1] > arr[2]) return true;
            else return false;

        }
        bool mountFound = false;

        for(int i =1; i< N-1; ++i)
        {
            if((arr[i] == arr[i+1] )|| ( arr[i] == arr[i-1])) return false;
            else if(!mountFound && arr[i-1] > arr[i]) return false;
            else if((arr[i-1] < arr[i]) && (arr[i] > arr[i+1]))
            {
                mountFound = true;
            }else if(mountFound && arr[i]< arr[i+1]) return false;
        }

        if(mountFound) return true;

        return false;
    }
};


int main()
{
    Solution sol;
    vector<int> v{0,3,2, 1};

    cout<<boolalpha<<sol.validMountainArray(v)<<endl;

    return 0;
}