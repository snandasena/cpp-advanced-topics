//
// Created by sajith on 5/8/22.
//

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#include "base.h"


class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
    int pos = 0;
    vector<int> v;

    void flatten(const vector<NestedInteger> &nested_list)
    {
        for (auto item: nested_list)
        {
            if (item.isInteger())
            {
                v.push_back(item.getInteger());
            }
            else
            {
                flatten(item.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        flatten(nestedList);
    }

    int next()
    {
        return v[pos++];
    }

    bool hasNext()
    {
        return pos < v.size();
    }
};