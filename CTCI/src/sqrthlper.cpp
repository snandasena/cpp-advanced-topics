//
// Created by sajith on 11/28/21.
//

#include "base.h"

int sqrt_helper(int n, int mn, int mx)
{
    if (mx < mn) return -1;

    int md = mn + (mx - mn) / 2;
    int guess = md * md;
    if (guess == n) return md;
    else if (guess < n) return sqrt_helper(n, md + 1, mx);
    else return sqrt_helper(n, mn, md - 1);
}


int main()
{
    int n = 100000;
    cout << sqrt_helper(n, 1, n) << endl;
}