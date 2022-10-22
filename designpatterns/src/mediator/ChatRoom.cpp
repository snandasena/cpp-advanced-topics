//
// Created by sajith on 10/21/22.
//

#include "ChatRoom.h"


void ChatRoom::message(const string &origin, const string &who, const string &message)
{
    std::input_iterator auto target = ranges::find_if(people.begin(), people.end(),
                                                      [&](const Person *person)
                                                      {
                                                          return person->name == who;
                                                      });

    if (target != people.end())
    {
        (*target)->receive(origin, message);
    }

}