
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


void test()
{
    auto w1 = make_unique<Widget>("W1");
    API02(move(w1));
    auto w2 = make_unique<Widget>("W2");
    API01(w2);
    API03(w2.get());
//    API03(move(w1));
}

int main()
{
    test();
    return 0;
}