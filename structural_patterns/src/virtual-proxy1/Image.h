//
// Created by sajith on 7/18/21.
//

#ifndef ADVANCED_TOPICS_IMAGE_H
#define ADVANCED_TOPICS_IMAGE_H

#include <string>

class Image
{

    std::string m_Filename;

protected:
    void SetFilename(const std::string &filename);

public:
    Image() = default;

    Image(const std::string &filename);

    const std::string &GetFilename() const;

    virtual ~Image() = default;

    virtual void Display() = 0;

    virtual void Load() = 0;

    virtual void Load(const std::string &filename) = 0;

};

#endif //ADVANCED_TOPICS_IMAGE_H
