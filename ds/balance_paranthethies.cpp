//
// Created by sajith on 5/3/21.
//

#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

map<char, char> open_parenthesis;
map<char, char> close_parenthesis;


bool is_valid_exp(string *epxr)
{
    stack<char> stack;
    for (const auto &c: *epxr)
    {
        if (open_parenthesis[c]) // (, {, [
        {
            stack.push(c);
        } else // ), }, ]
        {
            if (stack.empty() || stack.top() != close_parenthesis[c])
            {
                return false;
            } else if (stack.top() == close_parenthesis[c])
            {
                stack.pop();
            }
        }
    }
    return stack.empty();
}

int main()
{
    open_parenthesis['('] = ')';
    open_parenthesis['['] = ']';
    open_parenthesis['{'] = '}';

    close_parenthesis[')'] = '(';
    close_parenthesis[']'] = '[';
    close_parenthesis['}'] = '{';


    string exp = "{([()])}";
    cout<<boolalpha<<is_valid_exp(&exp);

    return 0;
}