//
// Created by sajith on 10/21/22.
//

#ifndef ADVANCED_TOPICS_CHATROOM_H
#define ADVANCED_TOPICS_CHATROOM_H

#include "Person.h"
#include <algorithm>

struct ChatRoom
{
    vector<Person *> people;

    void brodcast(const string &origin, const string &message);

    void join(Person *p);

    void message(const string &origin, const string &who, const string &message);

};

#endif //ADVANCED_TOPICS_CHATROOM_H
