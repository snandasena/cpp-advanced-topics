//
// Created by sajith on 10/19/22.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include "EmployeeManager.h"

class MockDatabaseConnection : public IDatabaseConnection
{
public:
    MockDatabaseConnection(const std::string &serverAddress);

    MOCK_METHOD0(connect, void());
    MOCK_METHOD0(disconnect, void());

    MOCK_CONST_METHOD1(getSalary, float(int));
    MOCK_METHOD2(updateSalary, void(int, float));

    MOCK_CONST_METHOD1(getSalariesRange, std::vector<Employee>(float));
    MOCK_CONST_METHOD2(getSalariesRange, std::vector<Employee>(float, float));

    void someMemberMethod(std::string param)
    {
        std::cout << "Member method called with param = " << param << '\n';
        throw std::runtime_error{"Dummy error"};
    }

};

MockDatabaseConnection::MockDatabaseConnection(const std::string &serverAddress) : IDatabaseConnection(serverAddress)
{

}

TEST(TestEmployeManager, TestConnectionError)
{
    MockDatabaseConnection dbConnection("dummyAddress");
    EXPECT_CALL(dbConnection, connect()).WillOnce(testing::Throw(std::runtime_error{"Dummy error"}));

    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection), std::runtime_error);
}

ACTION(myThrow)
{
    std::cout << "Throwing an error!\n";
    throw std::runtime_error{"Dummy error"};
}

TEST(TestEmployeManager, TestConnectionErrorAction)
{
    MockDatabaseConnection dbConnection("dummyAddress");
    EXPECT_CALL(dbConnection, connect()).WillOnce(myThrow());

    ASSERT_THROW(EmployeeManager _(&dbConnection), std::runtime_error);
}

void someFreeFunction()
{
    std::cout << "Free function\n";
    throw std::runtime_error{"Dummy exception"};
}

TEST(TestEmployeManager, TestConnectionErorInvoke)
{
    MockDatabaseConnection dbConnection("dummyAddress");

    auto boundMethod = std::bind(&MockDatabaseConnection::someMemberMethod, &dbConnection, "Some param");
    EXPECT_CALL(dbConnection, connect()).WillOnce(testing::InvokeWithoutArgs(boundMethod));

    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection), std::runtime_error);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}