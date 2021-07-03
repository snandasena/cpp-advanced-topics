//
// Created by sajith on 7/3/21.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TestStruct
{
    string str;
    int val{};

    TestStruct(const string &str1, const int &val1)
    {
        str = str1;
        val = val1;
    }

};

struct MyCollection
{

    vector<TestStruct> items;

    void operator+=(const TestStruct &&item) // R-value reference
    {
        this->items.push_back(item);
    }

    void operator+=(const TestStruct &item) // L-value reference
    {
        this->items.push_back(item);
    }

    void operator-=(const TestStruct &item)
    {
        for (auto i = this->items.begin(); i != this->items.end(); ++i)
        {
            if (i->str == item.str)
            {
                this->items.erase(i);
                break;
            }
        }
    }
};

ostream &operator<<(ostream &os, const TestStruct &strt)
{
    os << "str: " << strt.str << endl;
    os << "val: " << strt.val << endl;
    return os;
}


ostream &operator<<(ostream &os, MyCollection &myCollection)
{
    for (const auto &item: myCollection.items)
    {
        os << item;
    }
    return os;
}

int main()
{
    TestStruct testStruct1 = TestStruct("test string1", 1);
    TestStruct testStruct2 = TestStruct("test string2", 2);
    cout << testStruct1 << testStruct2;

    cout << endl;

    MyCollection myCollection;
    vector<TestStruct> items;
    items.push_back(testStruct1);
    items.push_back(testStruct2);

    myCollection.items = items;

    TestStruct testStruct3 = TestStruct("test string3", 3);
    myCollection += testStruct3;
    myCollection += TestStruct("test string4", 4);

    cout << myCollection;

    myCollection -= testStruct2;

    cout << endl;
    cout << myCollection;
    return 0;
}
