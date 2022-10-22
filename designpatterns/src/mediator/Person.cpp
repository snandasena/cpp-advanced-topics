//
// Created by sajith on 10/21/22.
//

#include "Person.h"
#include "ChatRoom.h"

#include <iostream>

Person::Person(const string &n) : name{n}
{}

void Person::say(const string &message) const
{
    room->brodcast(name, message);
}

void Person::pm(const string &who, const string &message) const
{
    room->message(name, who, message);
}

void Person::receive(const string &origin, const string &message)
{
    string s{origin + ": \"" + message + "\""};
    std::cout << "[" << name << "'s chat session] " << s << '\n';
    chat_log.emplace_back(s);
}

bool Person::operator==(const Person &rhs) const
{
    return name == rhs.name;
}

bool Person::operator!=(const Person &rhs) const
{
    return !(rhs == *this);
}

