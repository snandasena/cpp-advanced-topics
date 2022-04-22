//
// Created by sajith on 4/22/22.
//

#include "base.h"

class MyHashMap
{
    vector<pair<bool, int>> mp;
public:
    MyHashMap()
    {
        mp.resize(1e6 + 1, {false, -1});
    }

    void put(int key, int value)
    {
        mp[key] = {true, value};
    }

    int get(int key)
    {
        return mp[key].second;
    }

    void remove(int key)
    {
        mp[key] = {false, -1};
    }
};


int main()
{
    MyHashMap myHashMap;
    return 0;
}