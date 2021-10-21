//
// Created by sajith on 10/21/21.
//

#include "base.h"


class RandomizedSet
{
private:
    unordered_map<int, int> mp;
    vector<int> container;
public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (mp.find(val) != mp.end())
        {
            return false;
        }
        container.emplace_back(val);
        mp.insert({val, container.size() - 1});
        return true;
    }

    bool remove(int val)
    {
        if (mp.find(val) == mp.end())
        {
            return false;
        }
        int pos = mp[val];
        container[pos] = container[container.size() - 1];
        mp[container[pos]] = pos;
        container.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom()
    {
        return container[rand() % container.size()];
    }
};

int main()
{
    RandomizedSet randomizedSet;
    cout << boolalpha << randomizedSet.insert(1) << endl;
    cout << boolalpha << randomizedSet.remove(2) << endl;
    cout << boolalpha << randomizedSet.insert(2) << endl;
    cout << boolalpha << randomizedSet.getRandom() << endl;
    cout << boolalpha << randomizedSet.remove(1) << endl;
    cout << boolalpha << randomizedSet.insert(2) << endl;
    cout << boolalpha << randomizedSet.getRandom() << endl;

    return 0;
}