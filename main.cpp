

#include <bits/stdc++.h>

using namespace std;

struct A
{
    void disp()
    {
        cout << "Base A\n";
    }
};


struct B : A
{
    void disp()
    {
        cout << "Base B\n";
    }
};

struct C : B
{
    void disp()
    {
        cout << "C child\n";
    }
};


struct D : A
{
    void disp()
    {
        cout << "Base D";
    }
};

struct F : virtual B, virtual D
{
    void disp()
    {
        B::disp();
    }
};

int BinaryGap(int N)
{
    int y = N;
    int i = 0;
    while (y != 0)
    {
        ++i;
        y /= 2;
    }

    int start = 0;
    int end = 0;
    bool flag{false};
    int x = 1;
    int k = 1;
    for (int j = 0; j <= i; ++j)
    {
        y = (N & x);
        if (!flag && y != 0)
        {
            flag = true;
            start = j;
            k = x;
        }

        if (y != 0)
        {
            end = j;
        }

        x *= 2;
    }

    if (start == end) return 0;
    x = k;
    int curr = 0;
    int ans = 0;
    for (int j = start; j <= end; ++j)
    {
        y = (N & x);
        if (y == 0)
        {
            ++curr;
        }
        else
        {
            ans = max(curr, ans);
            curr = 0;
        }

        x *= 2;
    }
    return ans;
}


int missing_number(vector<int> &v)
{
    int N = v.size();
    sort(v.begin(), v.end());
    for (int i = 1; i <= N; ++i)
    {
        if (i != v[i - 1]) return i;
    }

    return N + 1;
}

int main()
{

    vector<int> v{1};//{1, 3, 2, 4, 5};

    cout << missing_number(v) << endl;
    return 0;
}

// 14 + 13 = 27