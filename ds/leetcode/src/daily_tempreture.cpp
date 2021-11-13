//
// Created by sajith on 11/13/21.
//

#include "base.h"

class Solution
{
public:
    vector<int> dailyTemperatures1(vector<int> &temperatures)
    {
        vector<int> res;
        int indx;
        bool isbreak;
        int j;
        for (int i = 0; i < temperatures.size() - 1; ++i)
        {
            indx = i;
            if (temperatures[i] < temperatures[i + 1])
            {
                res.push_back(1);
            }
            else
            {
                isbreak = false;
                for (j = i + 1; j < temperatures.size(); ++j)
                {
                    if (temperatures[i] < temperatures[j])
                    {
                        isbreak = true;
                        break;
                    }
                }
                if (isbreak) indx = j;
                res.push_back(indx - i);
            }
        }

        res.push_back(0);
        return res;
    }


    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> stck;
        vector<int> res(temperatures.size(), 0);
        int curr_temp, prev_day;
        for (int curr_day = 0; curr_day < temperatures.size(); ++curr_day)
        {
            curr_temp = temperatures[curr_day];
            while (!stck.empty() && temperatures[stck.top()] < curr_temp)
            {
                prev_day = stck.top();
                stck.pop();
                res[prev_day] = curr_day - prev_day;
            }
            stck.push(curr_day);
        }
        return res;
    }
};


class Solution1
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        size_t len = temperatures.size();
        vector<int> next(len, 0);
        int j;
        for (int i = len - 1; i >= 0; --i)
        {
             j= i + 1;
            while (j < len && temperatures[j] <= temperatures[i] > 0)
            {
                j = next[j] > 0? next[j] + j: len;
            }
            if (j < len)
            {
                next[i] = j - i;
            }
        }
        return next;
    }
};

int main()
{
    Solution solution;
    vector<int> v = {10, 10, 10, 10};
    solution.dailyTemperatures(v);
    return 0;
}