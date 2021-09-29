//
// Created by sajith on 9/28/21.
//

#include "base.h"

class dog
{

private:
    string m_name;
public:
    dog(string name) { m_name = name; }

    operator string() const { return m_name; }
};

int main()
{
    string name = "dog name";
    dog d1 = name;
    printf("dog name is %s. \n", d1);
    return 0;
}