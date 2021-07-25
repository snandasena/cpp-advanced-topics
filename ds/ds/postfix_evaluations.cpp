//
// Created by sajith on 5/4/21.
//

#include<iostream>
#include<string>
#include<stack>
#include <set>

using namespace std;

set<char> operators;

int EvaluatePostfix(const string *);

int PerformOperation(const char *opetr, const int *operand1, const int *operand2);

bool IsNumericDigit(const char *c);

int main()
{
    operators.insert('+');
    operators.insert('*');
    operators.insert('/');
    operators.insert('-');

    string exp = "1 2 -";
    cout << EvaluatePostfix(&exp) << endl;

    return 0;
}


int EvaluatePostfix(const string *exp)
{
    stack<int> s;
    for (int i = 0; i < exp->length(); ++i)
    {

        if (exp->at(i) == ' ' or exp->at(i) == ',')
        {
            continue;
        } else if (operators.count(exp->at(i)) == 1)
        {
            int operand1 = s.top();
            s.pop();
            int operand2 = s.top();
            s.pop();

            int result = PerformOperation(&exp->at(i), &operand1, &operand2);
            s.push(result);

        } else if (IsNumericDigit(&exp->at(i)))
        {
            int operand = 0;
            while (i < exp->length() && IsNumericDigit(&exp->at(i)))
            {
                operand = (operand * 10) + (exp->at(i) - '0');
                i++;
            }
            i--;
            s.push(operand);
        }

    }

    return s.top();
}

int PerformOperation(const char *opetr, const int *operand1, const int *operand2)
{
    if (*opetr == '+') return *operand1 + *operand2;
    else if (*opetr == '-') return *operand1 - *operand2;
    else if (*opetr == '/') return *operand1 / *operand2;
    else if (*opetr == '*') return *operand1 * *operand2;
    else throw std::logic_error{"Invalid operator found!"};
}

bool IsNumericDigit(const char *c)
{
    if (*c >= '0' and *c <= '9')
    {
        return true;
    }
    return false;
}

