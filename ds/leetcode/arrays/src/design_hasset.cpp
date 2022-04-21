//
// Created by sajith on 4/21/22.
//

#include "base.h"

class MyHashSet
{
    vector<bool> keys;
public:
    MyHashSet()
    {
        keys.resize(1e6 + 1, false);
    }

    void add(int key)
    {
        keys[key] = true;
    }

    void remove(int key)
    {
        keys[key] = false;
    }

    bool contains(int key)
    {
        return keys[key];
    }
};