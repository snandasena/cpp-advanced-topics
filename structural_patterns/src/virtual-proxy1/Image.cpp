//
// Created by sajith on 7/18/21.
//

#include "Image.h"


void Image::SetFilename(const std::string &filename)
{
    m_Filename = filename;
}

Image::Image(const std::string &filename) : m_Filename(filename)
{

}

const std::string &Image::GetFilename() const
{
    return m_Filename;
}