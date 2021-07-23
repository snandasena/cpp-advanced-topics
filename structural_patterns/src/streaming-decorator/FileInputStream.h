//
// Created by sajith on 7/23/21.
//

#ifndef ADVANCED_TOPICS_FILEINPUTSTREAM_H
#define ADVANCED_TOPICS_FILEINPUTSTREAM_H

#include <fstream>
#include "InputStream.h"

class FileInputStream : public InputStream
{

    std::ifstream m_Reader;
public:
    FileInputStream() = default;

    FileInputStream(const std::string &filename);

    bool Read(std::string &text) override;

    void Close() override;

};

#endif //ADVANCED_TOPICS_FILEINPUTSTREAM_H
