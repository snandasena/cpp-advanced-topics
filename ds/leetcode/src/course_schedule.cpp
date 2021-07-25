//
// Created by sajith on 7/25/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indgree(numCourses, 0);
        unordered_map<int, list<int>> digraph;

        for (const auto &relation: prerequisites)
        {
            digraph[relation[1]].push_back(relation[0]);

            ++indgree[relation[0]];
        }

        queue<int> que;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indgree[i] == 0)
            {
                que.push(i);
            }
        }

        int count = 0;
        while (!que.empty())
        {
            int currCourse = que.front();
            que.pop();

            ++count;
            for (int nextCourse : digraph[currCourse])
            {
                --indgree[nextCourse];
                if (indgree[nextCourse] == 0)
                {
                    que.push(nextCourse);
                }
            }
        }

        return count == numCourses;
    }
};