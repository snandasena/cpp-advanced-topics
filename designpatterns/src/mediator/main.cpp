//
// Created by sajith on 10/21/22.
//

#include "ChatRoom.h"
#include "Person.h"

int main()
{
    ChatRoom room;
    Person john{"John"};
    Person jane{"Jane"};

    room.join(&john);
    room.join(&jane);

    john.say("hi");
    jane.say("hi");

    Person simon{"Simon"};
    room.join(&simon);
    simon.say("hi all");

    jane.pm("Simon", "Hi Simon");
}