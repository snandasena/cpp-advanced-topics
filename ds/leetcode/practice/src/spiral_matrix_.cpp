//
// Created by sajith on 7/3/22.
//

#include "base.h"


class Solution
{
public:
    vector<vector<int>> spiralMatrix(int M, int N, ListNode *head)
    {
        vector<int> arr;
        while (head != nullptr)
        {
            arr.push_back(head->val);
            head = head->next;
        }

        auto sz = (long long) (M) * N;
        if (arr.size() != sz)
        {
            while (arr.size() != sz)
            {
                arr.push_back(-1);
            }
        }


        vector<vector<int>> mat(M, vector<int>(N));

        int top = 0, bottom = M - 1;
        int left = 0, right = N - 1;

        int index = 0;

        while (1)
        {
            if (left > right)
            {
                break;
            }
            // print top row
            for (int i = left; i <= right; i++)
            {
                mat[top][i] = arr[index++];
            }
            top++;

            if (top > bottom)
            {
                break;
            }
            // print right column
            for (int i = top; i <= bottom; i++)
            {
                mat[i][right] = arr[index++];
            }
            right--;

            if (left > right)
            {
                break;
            }
            // print bottom row
            for (int i = right; i >= left; i--)
            {
                mat[bottom][i] = arr[index++];
            }
            bottom--;

            if (top > bottom)
            {
                break;
            }
            // print left column
            for (int i = bottom; i >= top; i--)
            {
                mat[i][left] = arr[index++];
            }
            left++;
        }
        return mat;
    }
};

int main()
{
    Solution solution;

    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(-1);

    solution.spiralMatrix(1, 4, head);


    return 0;

}