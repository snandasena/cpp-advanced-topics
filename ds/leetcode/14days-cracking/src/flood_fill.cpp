//
// Created by sajith on 9/29/21.
//

#include "base.h"

class Solution
{
public:

    void fill(vector<vector<int>> &image, int r, int c, int newColor, int oldColor)
    {
        if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size() || oldColor != image[r][c])
        {
            return;
        }
        image[r][c] = newColor;
        fill(image, r + 1, c, newColor, oldColor);
        fill(image, r - 1, c, newColor, oldColor);
        fill(image, r, c + 1, newColor, oldColor);
        fill(image, r, c - 1, newColor, oldColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] == newColor) return image;
        fill(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }


    vector<vector<int>> floodFill2(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] == newColor) return image;
        queue<pair<int, int>> que;
        que.push({sr, sc});
        int ep[4][2] = {{1,  0},
                        {-1, 0},
                        {0,  1},
                        {0,  -1}};
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        while (!que.empty())
        {
            auto pr = que.front();
            que.pop();
            for (auto & i : ep)
            {
                int r = pr.first + i[0];
                int c = pr.second + i[1];

                if (r >= 0 && c >= 0 && r < image.size() && c < image[0].size() && oldColor == image[r][c])
                {
                    image[r][c] = newColor;
                    que.push({r, c});
                }
            }
        }
        return image;
    }
};