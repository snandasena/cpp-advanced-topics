//
// Created by sajith on 6/26/21.
//

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 2)
        {
            cout << "2 1\n";
        } else if (n == 3)
        {
            cout << "3 2 1\n";
        } else
        {
            for (int i = 1; i <= n; ++i)
            {
                if (i % 2 == 0)
                {
                    cout << i - 1 << " ";
                } else
                {
                    
                }
            }
        }
    }
}