//
// Created by sajith on 7/23/21.
//

#include "FileInputStream.h"

FileInputStream::FileInputStream(const std::string &filename)
{
    m_Reader.open(filename);
    if (!m_Reader)
    {
        throw std::runtime_error{"Could not open the file for reading"};
    }
}

bool FileInputStream::Read(std::string &text)
{
    text.clear();

    std::getline(m_Reader, text);
    return !text.empty();
}

void FileInputStream::Close()
{
    if (m_Reader.is_open())
    {
        m_Reader.close();
    }
}