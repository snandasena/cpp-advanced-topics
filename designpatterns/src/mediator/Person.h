//
// Created by sajith on 10/21/22.
//

#ifndef ADVANCED_TOPICS_PERSON_H
#define ADVANCED_TOPICS_PERSON_H

#include<string>
#include<vector>

using namespace std;

struct ChatRoom;

struct Person
{
    string name;
    ChatRoom *room{nullptr};
    vector<string> chat_log;

    Person(const string &n);

    void say(const string &messge) const;

    void pm(const string &who, const string &message) const;

    void receive(const string &origin, const string &message);

    bool operator==(const Person &rhs) const;

    bool operator!=(const Person &rhs) const;
};

#endif //ADVANCED_TOPICS_PERSON_H
