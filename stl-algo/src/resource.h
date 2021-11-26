//
// Created by sajith on 11/25/21.
//

#ifndef ADVANCED_TOPICS_RESOURCE_H
#define ADVANCED_TOPICS_RESOURCE_H


class Resource
{
    int i =1;
    static int objectCount;

public:
    Resource();
    Resource(Resource const &r);
    Resource &operator=(Resource const &r);
    ~Resource();

    void setValue(int ii) { i == ii; }

    int getValue() const { return i; }
};


#endif //ADVANCED_TOPICS_RESOURCE_H
