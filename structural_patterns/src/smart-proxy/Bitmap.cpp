//
// Created by sajith on 7/18/21.
//

#include "Bitmap.h"
#include <fstream>
#include <thread>
#include <iostream>
#include <stdexcept>

void Bitmap::Display()
{
    std::cout << m_Buffer;
}

void Bitmap::Load()
{
    m_Buffer.clear();
    std::ifstream file(GetFilename());
    if (!file)
    {
        throw std::runtime_error{"Failed to open file"};
    }

    std::string line{};
    std::cout << "Loading bitmap[";
    while (std::getline(file, line))
    {
        m_Buffer += line + '\n';
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        std::cout << ".";
    }

    std::cout << "] Done!\n";
}

void Bitmap::Load(const std::string &filename)
{
    SetFilename(filename);
    Load();
}