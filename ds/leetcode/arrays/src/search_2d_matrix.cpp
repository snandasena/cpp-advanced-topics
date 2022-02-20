//
// Created by sajith on 2/20/22.
//

#include "base.h"

class Solution
{
public:
    bool searchMatrix1(vector<vector<int>> &matrix, int target)
    {

        int low = 0;
        auto M = static_cast<int > (matrix[0].size());
        auto high = static_cast<int >(matrix.size() * M) - 1;
        int mid;
        int row;
        int col;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            row = mid / M;
            col = mid % M;

            if (matrix[row][col] == target)return true;
            else if (matrix[row][col] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int low = 0;
        int high = matrix.size();
        int mid1;
        int mid2;
        int start;
        int end;
        while (low < high)
        {
            mid1 = low + (high - low) / 2;

            start = 0;
            end = matrix[mid1].size();

            for (int i = 0; i < end; ++i)
            {
                if(matrix[mid1][i] == target) return true;
            }

            if (matrix[mid1][0] > target)
            {
                high = mid1 - 1;
            }
            else
            {
                low = mid1 + 1;
            }
        }
        return false;
    }

};