//
// Created by sajith on 7/23/21.
//

#include <iostream>
#include "BufferOutputStream.h"

void BufferedOutputStream::Write(const std::string &text)
{
    std::cout << "Buffered Write\n";

    FileOutputStream::Write(text);
}

void BufferedOutputStream::Close()
{
    FileOutputStream::Close();
}
