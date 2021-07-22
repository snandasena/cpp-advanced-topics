//
// Created by sajith on 7/22/21.
//

#include <memory>
#include <iostream>

using namespace std;

class A
{
public:

    A()
    {
        cout << "Constructor called\n";
    }

    ~A()
    {
        cout << "Destructor called\n";
    }

};

int main()
{
    unique_ptr<int> uPtr = make_unique<int>(1213);
    cout << *uPtr << endl;

    unique_ptr<int> movedPtr = std::move(uPtr);
    if (uPtr)
    {
        cout << "This is not null\n";
    }
    cout << *movedPtr << endl;

    {
        // unique pointer demo
        unique_ptr<A> m_pA = make_unique<A>();
    }


    {
        // shared pointer demo
        shared_ptr<A> sharedPrt1 = make_shared<A>();
        cout << sharedPrt1.use_count() << endl;

        {
            shared_ptr<A> sharedPtr2 = sharedPrt1;
            cout << sharedPrt1.use_count() << endl;
        }
        cout << sharedPrt1.use_count() << endl;
    }



    return 0;
}