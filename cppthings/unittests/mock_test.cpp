//
// Created by sajith on 11/10/21.
//

#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

using namespace std;
using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;


class Database
{
public:
    virtual bool login(const string &username, const string &password) { return true; }

    virtual bool logout(const string &username) { return true; }

    virtual int fetchRecord() { return -1; }
};

class MyDatabase
{
    Database &dbc;
public:
    MyDatabase(Database &_dbc) : dbc(_dbc) {}

    int Init(const string &username, const string &password)
    {
        if (dbc.login(username, password))
        {
            cout << "DB SUCCESS\n";
            return 1;
        }
        else
        {
            cout << "DB FAILURE\n";
            return -1;
        }
    }
};

class MyMockDB : public Database
{
public:
    MOCK_METHOD0(fetchRecord, int());
    MOCK_METHOD1(logout, bool(string));
    MOCK_METHOD2(login, bool(string, string));
};


TEST(MyDBtest, LoginTest)
{
    // Arrange
    MyMockDB mdb;
    MyDatabase db(mdb);

    EXPECT_CALL(mdb, login(_, _))
        .Times(AtLeast(1))
        .WillOnce(Return(true));

    // act
    int returnVal = db.Init("test", "testpass");
    // Asserts
    EXPECT_EQ(returnVal, 1);
}


int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}