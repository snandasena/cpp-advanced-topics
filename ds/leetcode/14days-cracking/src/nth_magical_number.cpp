//
// Created by sajith on 12/11/21.
//

#include "base.h"

class Solution
{
    int const MOD = 1'000'000'007;

    int gcd(int a, int b)
    {
        if (a == 0) return b;
        return gcd(b % a, a);
    }

public:
    int nthMagicalNumber(int N, int A, int B)
    {
        int L = A / gcd(A, B) * B;

        long int l = 0;
        long r = (long) N * min(A, B);
        long int mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;

            if (mid / A + mid / B - mid / L < N)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        return static_cast<int >(l % MOD);
    }
};


int main()
{
    int x = 0xffff;
    cout << x << endl;
    return 0;
}