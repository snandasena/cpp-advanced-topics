//
// Created by sajith on 7/23/21.
//

#ifndef ADVANCED_TOPICS_BUFFEROUTPUTSTREAM_H
#define ADVANCED_TOPICS_BUFFEROUTPUTSTREAM_H


#include "FileOutputStream.h"

class BufferedOutputStream : public FileOutputStream
{

    char m_Buffer[512]{};
    using FileOutputStream::FileOutputStream;

public:
    void Write(const std::string &text) override;
    void Close() override;

};

#endif //ADVANCED_TOPICS_BUFFEROUTPUTSTREAM_H
