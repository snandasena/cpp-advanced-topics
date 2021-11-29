//
// Created by sajith on 11/29/21.
//

#include "base.h"

class Solution
{
    unordered_map<string, vector<int>> m;
    vector<bool> visited;


    void dfs(vector<vector<string>> &accounts, int i, set<string, less<>> &emails)
    {
        if (visited[i]) return;
        visited[i] = true;

        for (int j = 1; j < accounts[i].size(); ++j)
        {
            string curr = accounts[i][j];
            emails.insert(curr);
            for (auto nei: m[curr])
            {
                dfs(accounts, nei, emails);
            }
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        vector<vector<string >> res;
        visited.assign(accounts.size(), false);

        for (int i = 0; i < accounts.size(); ++i)
        {
            for (int j = 1; j < accounts[i].size(); ++j)
            {
                m[accounts[i][j]].push_back(i);
            }
        }


        for (int i = 0; i < accounts.size(); ++i)
        {
            if (!visited[i])
            {
                set<string, less<>> emails;
                dfs(accounts, i, emails);

                vector<string> curr{accounts[i][0]};
                for (auto const &email: emails) curr.push_back(email);

                res.push_back(curr);
            }
        }
        return res;
    }
};