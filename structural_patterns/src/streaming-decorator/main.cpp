//
// Created by sajith on 7/23/21.
//

#include <iostream>
#include "FileInputStream.h"
#include "FileOutputStream.h"
#include "BufferedInputStream.h"
#include "BufferOutputStream.h"

void Read()
{
//    FileInputStream input{"test.txt"};
    BufferedInputStream input{"test.txt"};
    std::string text{};

    while (input.Read(text))
    {
        std::cout << text << "\n";
    }

    input.Close();
}


void Write()
{

//    FileOutputStream output{"test.txt"};
    BufferedOutputStream output{"test.txt"};
    output.Write("First line");
    output.Write("Second line");
    output.Write("Third line");

    output.Close();
}

int main()
{

    Write();
    Read();
    return 0;
}