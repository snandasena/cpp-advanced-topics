//
// Created by sajith on 3/19/22.
//

#include "base.h"

class FreqStack
{
    map<int, int> freq;
    map<int, stack<int>> group;
    int maxfreq{0};
public:
    FreqStack()
    {

    }

    void push(int x)
    {
        ++freq[x];
        maxfreq = max(maxfreq, freq[x]);
        group[freq[x]].push(x);
    }

    int pop()
    {
        int mx_freq = group[maxfreq].top();
        group[maxfreq].pop();
        --freq[mx_freq];
        if (group[maxfreq].size() == 0)
        {
            --maxfreq;
        }
        return mx_freq;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */