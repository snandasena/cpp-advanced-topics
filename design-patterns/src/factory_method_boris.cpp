//
// Created by sajith on 11/8/21.
//

#include <iostream>
#include <memory>
#include <functional>

using namespace std;

struct Connection
{
    virtual ~Connection() = default;
    virtual void send(const char *) = 0;
};

struct TCPConnection : public Connection
{
    void send(const char *s) override
    {
        cout << "TCP: " << s << endl;
    }
};

struct UDPConnection : public Connection
{
    void send(const char *s) override
    {
        cout << "UDP: " << s << endl;
    }
};


//struct TCPConnectionFactory
//{
//
//    TCPConnection make()
//    {
//        return TCPConnection();
//    }
//};


struct TCPConnectionFactory
{

    unique_ptr<TCPConnection> operator()()
    {
        return std::make_unique<TCPConnection>();
    }
};

//struct UDPConnectionFactory
//{
//    UDPConnection make()
//    {
//        return UDPConnection();
//    }
//};

struct UDPConnectionFactory
{
    unique_ptr<UDPConnection> operator()()
    {
        return make_unique<UDPConnection>();
    }
};


template<class ConnectionFactory>
void send(ConnectionFactory &connectionFactory)
{
    auto con = connectionFactory();
    con->send("Hello\n");
}

int main()
{
    std::function<unique_ptr<Connection>()> tcpConnectionFactory = TCPConnectionFactory();
    send(tcpConnectionFactory);

    std::function<unique_ptr<Connection>()> udpConnectionFactory = UDPConnectionFactory();
    send(udpConnectionFactory);

    return 0;
}