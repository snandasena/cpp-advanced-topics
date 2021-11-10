//
// Created by sajith on 11/9/21.
//


#include <iostream>
#include <memory>
#include "gtest/gtest.h"

using namespace std;

class Employee
{
public:
    shared_ptr<string> name;
    char *department;

    Employee(const shared_ptr<string> &name, char *department) : name(name), department(department) {}
};


TEST(name, case1)
{
    ASSERT_TRUE(1 == 1);
    ASSERT_FALSE(1 == 3);
}

TEST(name, case2)
{
    ASSERT_EQ(1, 1);
}

int main()
{
    testing::InitGoogleTest();

    shared_ptr<string> name = make_shared<string>("Name of the employee");
    char *department = "IT DEPARTMENT";
    Employee employee(name, department);

    [employee]()
    {
        cout << employee.department << endl;
        cout << *employee.name << endl;
    }();
    return RUN_ALL_TESTS();

}