//
// Created by sajith on 7/23/21.
//

#include <iostream>
#include "BufferedInputStream.h"

bool BufferedInputStream::Read(std::string &text)
{
    auto res = FileInputStream::Read(text);
    std::cout << "Buffered Read\n";
    return res;
}

void BufferedInputStream::Close()
{
    FileInputStream::Close();
}
