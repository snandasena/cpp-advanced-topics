//
// Created by sajith on 7/23/21.
//

#ifndef ADVANCED_TOPICS_INPUTSTREAM_H
#define ADVANCED_TOPICS_INPUTSTREAM_H

#include <string>

class InputStream
{
public:
    virtual bool Read(std::string &text) = 0;
    virtual void Close() = 0;
    virtual ~InputStream() = default;
};

#endif //ADVANCED_TOPICS_INPUTSTREAM_H
