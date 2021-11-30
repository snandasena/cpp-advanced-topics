
#include "base.h"


#define CI(ch) int((ch) -'0')

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        auto rows = matrix.size();
        if(rows == 0) return 0;
        auto cols = matrix[0].size();
        if(cols == 0) return 0;

        vector<int> heights(cols, 0);
        vector<int> sL(cols, 0);
        vector<int> sR(cols, cols);

        int curr_l;
        int curr_r;
        int ans = 0;

        for (int i = 0; i < rows; ++i)
        {
            curr_l = 0;
            curr_r = cols;

            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    ++heights[j];
                    sL[j] = max(sL[j], curr_l);
                }
                else
                {
                    heights[j] = 0;
                    sL[j] = 0;
                    curr_l = j + 1;
                }
            }

            for (int j = cols - 1; j >= 0; --j)
            {
                if (matrix[i][j] == '1')
                {
                    sR[j] = min(sR[j], curr_r);
                }
                else
                {
                    sR[j] = cols;
                    curr_r = j;
                }
            }

            for (int j = 0; j < cols; ++j)
            {
                ans = max(ans, heights[j] * (sR[j] - sL[j]));
            }
        }
        return ans;
    }
};


int main()
{

    vector<vector<char>> v{{'1', '0', '1', '0', '0'},
                           {'1', '0', '1', '1', '1'},
                           {'1', '1', '1', '1', '1'},
                           {'1', '0', '0', '1', '0'}};

    Solution solution;
    solution.maximalRectangle(v);

    cout << CI('5') << endl;
}