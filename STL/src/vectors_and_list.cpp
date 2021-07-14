//
// Created by sajith on 7/13/21.
//

#include <iostream>
#include <vector>

using namespace std;


void print(const vector<int> &my_vector)
{
    cout << "Vector content: { ";
    for (const int &number: my_vector)
    {
        cout << number << " ";
    }
    cout << "}\n\n";
}

int main()
{
    vector<int> my_vector;
    for (int i = 1; i < 4; ++i)
    {
        my_vector.push_back(i);
    }
    print(my_vector);

    for (int i = 4; i < 7; ++i)
    {
        my_vector.insert(my_vector.begin(), i);
    }
    print(my_vector);

}