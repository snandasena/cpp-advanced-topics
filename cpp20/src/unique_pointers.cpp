
//
// Created by sajith on 9/17/22.
//

#include <memory>
#include <iostream>
#include <string>

using namespace std;

#define DEBUG

class Widget
{
    string str{"default"};

public:
    explicit Widget(const string &&_str) : str{_str}
    {}

    Widget() = default;

#ifdef DEBUG
    ~Widget()
    {
        cout << "Deleted " << str << endl;
    }
#endif

    [[nodiscard]]  string get_str() const
    { return str; }

    void set_str(string_view _str)
    {
        str = _str;
    }
};

void API01(const unique_ptr<Widget> &ptr)
{
    cout << ptr->get_str() << endl;
}

void API02(unique_ptr<Widget> ptr)
{
    cout << ptr->get_str() << endl;
}

void API03(const Widget *ptr)
{
    cout << ptr->get_str() << endl;
}

void API04(const unique_ptr<Widget> &ptr)
{
    ptr->set_str("new str");
}

void test()
{
    auto w1 = make_unique<Widget>("W1");
    API04(w1);
    cout<<w1->get_str()<<endl;
}

int main()
{
    test();
    return 0;
}