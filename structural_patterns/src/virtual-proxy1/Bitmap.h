//
// Created by sajith on 7/18/21.
//

#ifndef ADVANCED_TOPICS_BITMAP_H
#define ADVANCED_TOPICS_BITMAP_H

#include "Image.h"

class Bitmap : public Image
{
    std::string m_Buffer{};

public:
    using Image::Image;

    void Display() override;

    void Load() override;

    void Load(const std::string &filename) override;

};

#endif //ADVANCED_TOPICS_BITMAP_H
