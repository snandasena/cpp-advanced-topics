//
// Created by sajith on 7/18/21.
//

#ifndef ADVANCED_TOPICS_BITMAPPROXY_H
#define ADVANCED_TOPICS_BITMAPPROXY_H


#include "Image.h"
#include "Bitmap.h"

class BitmapProxy : public Image
{
    std::string m_Filename;
    Bitmap *m_pBitmap{};
    bool m_IsLoaded{false};

public:

//    using Image::Image;
    BitmapProxy();

    BitmapProxy(const std::string &filename);

    ~BitmapProxy() override;

    void Display() override;

    void Load() override;

    void Load(const std::string &filename) override;
};

#endif //ADVANCED_TOPICS_BITMAPPROXY_H
