//
// Created by sajith on 4/28/22.
//

#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
    vector<int> root;

public:

    explicit UnionFind(int size) : root(size)
    {
        iota(root.begin(), root.end(), 0);
    }

    int find(int x)
    {
        return root[x];
    }

    void unionSet(int x, int y)
    {
        int rootx = this->find(x);
        int rooty = this->find(y);
        if (rootx != rooty)
        {
            for (int &elem: root)
            {
                if (elem == rooty)
                {
                    elem = rootx;
                }
            }
        }
    }

    bool connected(int x, int y)
    {
        return this->find(x) == this->find(y);
    }

};


int main()
{

    cout << boolalpha;
    UnionFind uf(10);

    uf.unionSet(1, 2);
    uf.unionSet(2, 5);
    uf.unionSet(5, 6);
    uf.unionSet(6, 7);
    uf.unionSet(3, 8);
    uf.unionSet(8, 9);

    cout << uf.connected(1, 5) << endl;
    return 0;
}