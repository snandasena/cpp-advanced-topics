//
// Created by sajith on 10/19/22.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include "EmployeeManager.h"

class MockDatabaseConenction : public IDatabaseConnection
{
public:
    MockDatabaseConenction(const std::string &serverAddress);

    MOCK_METHOD0(connect, void());
    MOCK_METHOD0(disconnect, void());

    MOCK_CONST_METHOD1(getSalary, float(int));
    MOCK_METHOD2(updateSalary, void(int, float));

    MOCK_CONST_METHOD1(getSalariesRange, std::vector<Employee>(float));
    MOCK_CONST_METHOD2(getSalariesRange, std::vector<Employee>(float, float));

};

MockDatabaseConenction::MockDatabaseConenction(const std::string &serverAddress) : IDatabaseConnection(serverAddress)
{

}


TEST(TestEmployeManager, TestConnectionError)
{

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}