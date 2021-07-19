//
// Created by sajith on 7/19/21.
//

#ifndef ADVANCED_TOPICS_POINTER_H
#define ADVANCED_TOPICS_POINTER_H

template<typename T>
class Pointer
{
    T *m_ptr;

public:
    Pointer(T *ptr) : m_ptr(ptr)
    {

    }

    ~Pointer()
    {
        delete m_ptr;
    }

    T *Get()
    {
        return m_ptr;
    }

    T *operator->()
    {
        return m_ptr;
    };

    T &operator*()
    {
        return *m_ptr;
    }
};

#endif //ADVANCED_TOPICS_POINTER_H
