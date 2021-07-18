//
// Created by sajith on 7/17/21.
//

#ifndef ADVANCED_TOPICS_SUBJECT_H
#define ADVANCED_TOPICS_SUBJECT_H

class Subject
{
public:

    virtual ~Subject() = default    ;

    virtual void Request() = 0;
};

#endif //ADVANCED_TOPICS_SUBJECT_H
