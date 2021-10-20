//
// Created by sajith on 10/19/21.
//

#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    for (int j = 1; j <= 64; ++j)
    {
        cout<< (j<<1)<<endl;
        cout << bitset<8 * sizeof(int)>(j) << endl;
    }

    const int mx = 8;
    vector<int> v(mx, 77);
    for (int i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<< endl;
    }

    return 0;
}