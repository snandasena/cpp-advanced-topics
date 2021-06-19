//
// Created by sajith on 6/19/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        transpose(matrix);
        reflect(matrix);
    }

    void transpose(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                int temp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }

    void reflect(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n / 2; ++j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = temp;
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    Solution solution;
    solution.rotate(matrix);

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix.size(); ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;
}