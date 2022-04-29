//
// Created by sajith on 4/25/22.
//

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 */

#include "base.h"

class Iterator
{
    struct Data;
    Data *data;
public:
    Iterator(const vector<int> &nums);

    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator
{
    vector<int> _nums;
    size_t i = 0;
    size_t sz;
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums), _nums(nums), sz{nums.size()}
    {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        return _nums[i];
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        auto ele = _nums[i];
        ++i;
        return ele;
    }

    bool hasNext() const
    {
        return i < sz;
    }
};