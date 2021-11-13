//
// Created by sajith on 11/13/21.
//

#include "Person.h"
#include "Tweeter.h"
#include <iostream>
#include <memory>

using std::cout;
using std::endl;


int Dummy(Person &p)
{
    return p.GetNumber();
}


int main()
{
    Person kate("Kate", "Gregory", 32423);
    Person &rKate = kate;
    Person *pKate = &kate;

    Tweeter kateGregory("Kate", "Gregory", 12312, "@gregory");
    Person *pKateGregory = &kateGregory;
    Person &rpKateGregory = kateGregory;
    Tweeter &rtKategregory = kateGregory;

    cout << rKate.GetName() << endl;
    cout << pKate->GetName() << endl;
    cout << kateGregory.GetName() << endl;
    cout << rpKateGregory.GetName() << endl;
    cout << rtKategregory.GetName() << endl;
    cout << pKateGregory->GetName() << endl;


//    Person *someone = new Tweeter("Someone", "last", 1232,"@someone");
//    cout<<someone->GetName()<<endl;
//    delete someone;

    std::shared_ptr<Person> sPerson =
        std::make_shared<Tweeter>("shared name", "shared last", 233, "@shared");

    cout << sPerson->GetName() << endl;

    kate = kateGregory;
    cout << kate.GetName() << endl;

    int x;
    x = Dummy(kate);
    cout << x << endl;
    x = Dummy(kateGregory);
    cout << x << endl;
    return 0;
}