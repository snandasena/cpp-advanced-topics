//
// Created by sajith on 11/1/21.
//

#include "base.h"

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> stck;
        string curr;
        auto n = path.size();
        for (int i = 0; i < n; ++i)
        {
            while (i < n && path[i] == '/') ++i;

            while (i < n && path[i] != '/') curr += path[i++];

            if (curr == "..")
            {
                if (!stck.empty()) stck.pop();
            } else if (!curr.empty() && curr != ".") stck.push(curr);
            curr = "";
        }

        string ans;
        while (!stck.empty())
        {
            ans = "/" + stck.top() + ans;
            stck.pop();
        }
        return !ans.empty() ? ans : "/";
    }
};

int main()
{
    Solution solution;
    string path = "/../";
    cout << solution.simplifyPath(path) << endl;
    return 0;
}