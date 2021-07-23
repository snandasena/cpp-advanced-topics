//
// Created by sajith on 7/23/21.
//

#ifndef ADVANCED_TOPICS_FILEOUTPUTSTREAM_H
#define ADVANCED_TOPICS_FILEOUTPUTSTREAM_H


#include <fstream>
#include "OutputStream.h"

class FileOutputStream : public OutputStream
{

    std::ofstream m_Writer{};

public:
    FileOutputStream() = default;
    FileOutputStream(const std::string &filename);

    void Write(const std::string &text) override;
    void Close() override;

};

#endif //ADVANCED_TOPICS_FILEOUTPUTSTREAM_H
