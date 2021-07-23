//
// Created by sajith on 7/23/21.
//

#ifndef ADVANCED_TOPICS_BUFFEREDINPUTSTREAM_H
#define ADVANCED_TOPICS_BUFFEREDINPUTSTREAM_H

#include "FileInputStream.h"

class BufferedInputStream : public FileInputStream
{

    using FileInputStream::FileInputStream;
    char m_Buffer[512]{};
public:

    bool Read(std::string &text) override;
    void Close() override;

};

#endif //ADVANCED_TOPICS_BUFFEREDINPUTSTREAM_H
