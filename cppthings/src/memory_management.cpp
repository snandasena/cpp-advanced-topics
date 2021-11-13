//
// Created by sajith on 11/13/21.
//

#include "Resource.h"
#include <string>

using std::string;

int main()
{
    {
        Resource localResource("Local");
        string localString = localResource.GetName();
    }

    Resource *pResource = new Resource("Created with new");
    string newString = pResource->GetName();

    Resource *p2 =pResource;
    delete pResource;
    pResource = nullptr;
//    string  string2 = p2->GetName();
    delete pResource;
//    delete p2;

//    string string1 = pResource->GetName();
    return 0;
}