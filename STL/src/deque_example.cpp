//
// Created by sajith on 7/14/21.
//

#include <deque>
#include <iostream>

using namespace std;

int main()
{
    deque<int> numbers;

    for (int i = 0; i < 20; ++i)
    {
        numbers.push_back(i);
    }

    deque<int>::iterator it;
    
    return 0;
}