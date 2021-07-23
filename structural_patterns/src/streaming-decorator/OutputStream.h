//
// Created by sajith on 7/23/21.
//

#ifndef ADVANCED_TOPICS_OUTPUTSTREAM_H
#define ADVANCED_TOPICS_OUTPUTSTREAM_H

class OutputStream
{

public:
    virtual void Write(const std::string &text) = 0;
    virtual void Close() = 0;
    virtual ~OutputStream() = default;
};

#endif //ADVANCED_TOPICS_OUTPUTSTREAM_H
