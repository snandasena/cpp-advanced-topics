//
// Created by sajith on 7/18/21.
//

#include "BitmapProxy.h"
#include <iostream>


BitmapProxy::BitmapProxy() : BitmapProxy{""}
{

}

BitmapProxy::BitmapProxy(const std::string &filename)
{
    m_pBitmap = new Bitmap{filename};
}

BitmapProxy::~BitmapProxy()
{
    delete m_pBitmap;
}

void BitmapProxy::Display()
{
    if (!m_IsLoaded)
    {
        std::cout << "[Proxy] Loading Bitmap\n";

        if (m_Filename.empty())
        {
            m_pBitmap->Load();
        }
        else
        {
            m_pBitmap->Load(m_Filename);
        }

        m_pBitmap->Display();
    }
}

void BitmapProxy::Load()
{
    m_Filename.clear();
}

void BitmapProxy::Load(const std::string &filename)
{
    m_Filename = filename;
}