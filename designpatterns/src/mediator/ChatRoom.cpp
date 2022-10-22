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
void ChatRoom::brodcast(const string &origin, const string &message)
{
    for (const auto &p: people)
    {
        if (p->name != origin)
        {
            p->receive(origin, message);
        }
    }
}
void ChatRoom::join(Person *p)
{
    auto join_msg = p->name + " joins the chat";
    brodcast("room", join_msg);
    p->room = this;
    people.push_back(p);
}
