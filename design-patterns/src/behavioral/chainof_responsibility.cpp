//
// Created by sajith on 7/8/21.
//

#include <iostream>
#include <string>

class StringValidator
{
public:
    virtual ~StringValidator() = default;

    virtual StringValidator *setNext(StringValidator *next) = 0;

    virtual std::string validate(std::string) = 0;
};

class BaseValidator : public StringValidator
{

protected:
    StringValidator *next = nullptr;
public:
    virtual ~BaseValidator()
    {
        delete next;
    }

    StringValidator *setNext(StringValidator *nextValidator) override
    {
        next = nextValidator;
        return nextValidator;
    }

    virtual std::string validate(std::string validateString) override
    {
        if (this->next)
        {
            return this->validate(validateString);
        }

        return "Success!";
    }

};