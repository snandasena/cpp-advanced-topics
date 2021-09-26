//
// Created by sajith on 9/25/21.
//

#include <iostream>
#include <vector>

using namespace std;


/*Enter your code here*/

class Comparator
{
public:
    Comparator() = default;
    ~Comparator() = default;
    bool compare(int a, int b);
    bool compare(string a, string b);
    bool compare(vector<int> a, vector<int> b);
};

bool Comparator::compare(int a, int b)
{
    return a == b;
}

bool Comparator::compare(string a, string b)
{
    return a == b;
}

bool Comparator::compare(vector<int> a, vector<int> b)
{
    if (a.size() != b.size())
    {
        return false;
    }

    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i])
        {
            return false;
        }

    }
    return true;
}

int main()
{
    Comparator comp;
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int condition;
        cin >> condition;
        getchar();
        if (condition == 1)
        {
            string s1;
            getline(cin, s1);
            string s2;
            getline(cin, s2);
            if (comp.compare(s1, s2))
            {
                cout << "Same\n";
            } else
            {
                cout << "Different\n";
            }
        } else if (condition == 2)
        {
            int num1;
            cin >> num1;
            int num2;
            cin >> num2;
            if (comp.compare(num1, num2))
            {
                cout << "Same\n";
            } else
            {
                cout << "Different\n";
            }
        } else if (condition == 3)
        {
            int len1;
            cin >> len1;
            int len2;
            cin >> len2;

            vector<int> arr1;
            vector<int> arr2;

            for (int i = 0; i < len1; i++)
            {
                int val;
                cin >> val;
                arr1.push_back(val);
            }

            for (int i = 0; i < len2; i++)
            {
                int val;
                cin >> val;
                arr2.push_back(val);
            }

            if (comp.compare(arr1, arr2))
            {
                cout << "Same\n";
            } else
            {
                cout << "Different\n";
            }
        }
    }
    return 0;
}