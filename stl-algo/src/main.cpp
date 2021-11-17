//
// Created by sajith on 11/17/21.
//

#include <bits/stdc++.h>

using namespace std;

void test()
{
    priority_queue<int, vector<int>, bool (*)(int const &p1, int const &p2)>
        pq([](int const &num1, int const &num2)
           {
               return num2 > num1;
           });

    pq.push(10);
    pq.push(40);
    pq.push(20);
    pq.push(60);

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

}

int main()
{

    return 0;
}