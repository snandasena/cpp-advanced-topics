//
// Created by sajith on 9/19/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        for (char c: s)
        {
            if (!parse(c))
            {
                return false;
            }
        }

        return isFinalStateLegit();
    }

private:

    enum class Type
    {
        Sign,
        Digit,
        Dot,
        Exponent,
        Invalid
    };

    int current_state = 0;

    unordered_map<int, unordered_map<Type, int >> translation = {
        {0,
            {
                {Type::Digit, 1},
                {Type::Sign,     2},
                {Type::Dot,      3}
            }
        },
        {1,
            {
                {Type::Digit, 1},
                {Type::Dot,      4},
                {Type::Exponent, 5}
            }
        },
        {2,
            {
                {Type::Digit, 1},
                {Type::Dot,      3}
            }
        },
        {3,
            {
                {Type::Digit, 4}
            }
        },
        {
         4,
            {
                {Type::Digit, 4},
                {Type::Exponent, 5}
            }
        },
        {
         5,
            {
                {Type::Sign,  6},
                {Type::Digit,    7}
            }
        },
        {
         6,
            {
                {Type::Digit, 7}
            }
        },
        {
         7,
            {
                {Type::Digit, 7}
            }
        }
    };

    Type classify(char c)
    {
        if (c == '+' or c == '-') return Type::Sign;
        else if (c >= '0' and c <= '9') return Type::Digit;
        else if (c == '.') return Type::Dot;
        else if (c == 'e' or c == 'E') return Type::Exponent;
        else return Type::Invalid;
    }

    bool parse(char c)
    {
        Type type = classify(c);

        if (type == Type::Invalid) return false;

        if (translation[current_state].count(type) == 0) return false;

        current_state = translation[current_state][type];
        return true;
    }

    bool isFinalStateLegit() const
    {
        return (current_state == 1 or current_state == 4 or current_state == 7);
    }
};