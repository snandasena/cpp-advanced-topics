//
// Created by sajith on 5/19/21.
//

#ifndef ADVANCED_TOPICS_MY_CLASS_H
#define ADVANCED_TOPICS_MY_CLASS_H
class MyClass
{
private:
    int _member;

public:

    explicit MyClass(int val) : _member{val} {}

    void printVal()
    {
        std::cout << ", managed object " << this << " with val = " << _member << "\n";
    }
};
#endif //ADVANCED_TOPICS_MY_CLASS_H
