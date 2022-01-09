//
// Created by sajith on 1/9/22.
//

#include "base.h"

class Solution
{
    int d = 0;
    int x = 0;
    int y = 0;
    vector<vector<int>> dir{{0,  1},
                            {1,  0},
                            {0,  -1},
                            {-1, 0}};
public:
    bool isRobotBounded(string ins)
    {
        for (char const &c: ins)
        {
            if (c == 'L')
            {
                d = (d + 3) % 4;
            }
            else if (c == 'R')
            {
                d = (1 + d) % 4;
            }
            else
            {
                x += dir[d][0];
                y += dir[d][1];
            }
        }
        return x == 0 && y == 0 || d > 0;
    }
};