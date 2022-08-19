#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Message
{
public:
    Message()
    {}
    const string &get_text()
    {
        return text;
    }

    void set_text(const string &str)
    {
        text = str;
    }

    bool operator<(const Message &msg)
    {
        return this->order < msg.order;
    }

    const int &get_order()
    {
        return order;
    }
    void set_order(const int ind)
    {
        order = ind;
    }

private:
    string text;
    int order;
};

class MessageFactory
{
public:
    MessageFactory()
    {}
    Message create_message(const string &text)
    {
        Message m;
        m.set_text(text);
        m.set_order(order);
        ++order;
        return m;
    }

private:
    int order = 0;
};

class Recipient
{
public:
    Recipient()
    {}
    void receive(const Message &msg)
    {
        messages_.push_back(msg);
    }
    void print_messages()
    {
        fix_order();
        for (auto &msg: messages_)
        {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order()
    {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network
{
public:
    static void send_messages(vector<Message> messages, Recipient &recipient)
    {
        // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());
        for (auto msg: messages)
        {
            recipient.receive(msg);
        }
    }
};

void solve()
{
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text))
    {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}

class Matrix
{
public:
    Matrix() = default;

    Matrix operator+(Matrix &other)
    {
        Matrix res;
        res.a.resize(other.a.size(), vector<int>(other.a[0].size(), 0));
        for (int i = 0; i < this->a.size(); ++i)
        {
            for (int j = 0; j < this->a[i].size(); ++j)
            {
                res.a[i][j] = (this->a[i][j] + other.a[i][j]);
            }

        }
        return res;
    }

public:
    vector<vector<int>> a;
};


int main()
{
    Matrix x;
    Matrix y;
    Matrix res;
    res = x + y;
}
