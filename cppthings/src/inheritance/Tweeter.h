//
// Created by sajith on 11/13/21.
//

#ifndef ADVANCED_TOPICS_TWEETER_H
#define ADVANCED_TOPICS_TWEETER_H

#include "Person.h"
#include <string>

class Tweeter : public Person
{
private:
    std::string tweeterHandler;
public:
    Tweeter(std::string first, std::string last, int arbitrary, std::string handle);

    ~Tweeter();
    std::string GetName() const;

    int GetNumber() const { return 0; }

};


#endif //ADVANCED_TOPICS_TWEETER_H
