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

void solve2()
{
    Matrix x;
    Matrix y;
    Matrix res;
    res = x + y;
}

struct Workshop
{
    int start_time;
    int duration;
    int end_time;

    Workshop() = default;

    Workshop(int startTime, int duration, int endTime) : start_time(startTime), duration(duration), end_time(endTime)
    {}

    bool operator<(const Workshop &other)
    {
        return this->end_time < other.end_time;
    }
};

struct Available_Workshops
{
    int n;
    Workshop *workshops;

    Available_Workshops() = default;

    Available_Workshops(int x) : n{x}
    {
        workshops = new Workshop[n];
    }

    ~Available_Workshops()
    {
        delete[] workshops;
    }
};

Available_Workshops *initialize(int start_time[], int duration[], int n)
{
    Available_Workshops *availableWorkshops = new Available_Workshops(n);

    for (int i = 0; i < n; ++i)
    {
        availableWorkshops->workshops[i] = Workshop(start_time[i], duration[i], start_time[i] + duration[i]);
    }
    return availableWorkshops;
}

int CalculateMaxWorkshops(Available_Workshops *ptr)
{
    int n = ptr->n;
    int ans = 0;
    sort(ptr->workshops, ptr->workshops + n);
    int start_time = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ptr->workshops[i].start_time >= start_time)
        {
            ++ans;
            start_time = ptr->workshops[i].end_time;
        }
    }
    return ans;
}

int main()
{
    int n = 6; // number of workshops
//    cin >> n;
    // create arrays of unknown size n
    int *start_time = new int[n]{1, 3, 0, 5, 5, 8};
    int *duration = new int[n]{1, 1, 6, 2, 4, 1};

//    for (int i = 0; i < n; i++)
//    {
//        cin >> start_time[i];
//    }
//    for (int i = 0; i < n; i++)
//    {
//        cin >> duration[i];
//    }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr);

    delete ptr;
    delete[] start_time;
    delete[] duration;
    return 0;
}