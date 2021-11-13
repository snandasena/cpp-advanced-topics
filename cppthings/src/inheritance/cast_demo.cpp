//
// Created by sajith on 11/13/21.
//

#include <iostream>

#include "Person.h"
#include "Tweeter.h"
#include "Resource.h"


using std::cout;
using std::endl;

int main()
{
    Tweeter t("Kate", "Gregory", 12343, "@gregory");
    Person *p = &t;
//    Tweeter *pT = (Tweeter *)p;

    Tweeter *pT = static_cast<Tweeter *>(p);
    cout << pT->GetName() << endl;

    Resource r("local");
    Tweeter *pT2;

    pT2 = dynamic_cast<Tweeter *>(&r);

    if (pT2)
    {
        cout << pT2->GetName() << endl;
    }
    else
    {
        cout << "Error \n";
    }


    return 0;
}