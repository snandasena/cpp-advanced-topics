//
// Created by sajith on 7/8/21.
//

#include <iostream>
#include <regex>
#include <string>
#include <vector>

class StringValidator
{
public:
    virtual ~StringValidator() {};

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
            return this->next->validate(validateString);
        }

        return "Success!";
    }
};

class NotEmptyValidator : public BaseValidator
{

public:
    NotEmptyValidator() {};

    std::string validate(std::string testString) override
    {
        puts("Checking if empty...");
        if (testString.empty())
        {
            return "Please enter a value";
        }

        return BaseValidator::validate(testString);
    }
};

class LengthValidator : public BaseValidator
{
    size_t _min_length;

public:

    LengthValidator(int minlength) : _min_length(minlength)
    {

    }

    std::string validate(std::string testString) override
    {
        puts("Checking string length...");

        if (testString.length() < _min_length)
        {
            return "Please enter a valid length string";
        }

        return BaseValidator::validate(testString);
    }
};


class RegexValidator : public BaseValidator
{
    std::string _patternName;
    std::string _regexString;

public:

    RegexValidator(std::string pattern, std::string regex) : _patternName(pattern), _regexString(regex)
    {

    }

    std::string validate(std::string testString) override
    {
        puts("Checking regx match...");

        if (!std::regex_match(testString, std::regex(_regexString)))
        {
            return "The value entered does not match the proper format";
        }

        return BaseValidator::validate(testString);
    }
};

bool in_array(const std::string &value, const std::vector<std::string> &array)
{
    return std::find(array.begin(), array.end(), value) != array.end();
}

class HistoryValidator : public BaseValidator
{
    std::vector<std::string> _historyItems;

public:

    HistoryValidator(std::vector<std::string> history) : _historyItems(history) {}

    std::string validate(std::string testString) override
    {
        puts("Checking the string has been used before...");

        if (in_array(testString, _historyItems))
        {
            return "Please enter a new string";
        }

        return BaseValidator::validate(testString);
    }
};

int main()
{
    StringValidator *stringValidator = new BaseValidator;

    stringValidator
            ->setNext(new NotEmptyValidator)
            ->setNext(new LengthValidator(10));

    std::cout << stringValidator->validate("") << "\n\n";
    std::cout << stringValidator->validate("test sting to validate") << "\n\n";
    std::cout << stringValidator->validate("test") << std::endl;

    delete stringValidator;
    return 0;
}