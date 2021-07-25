//
// Created by sajith on 7/24/21.
//

#include <iostream>
#include <string>

bool isPalindrome(std::string input)
{
    if (input.empty() || input.length() == 1)
    {
        return true;
    }

    if (input[0] == input[input.length() - 1])
    {
        return isPalindrome(input.substr(1, input.length() - 2));
    }

    return false;
}


int main()
{

    std::cout << std::boolalpha << isPalindrome("racecar") << "\n";
    std::cout << std::boolalpha << isPalindrome("") << "\n";
    std::cout << std::boolalpha << isPalindrome("e") << "\n";
    std::cout << std::boolalpha << isPalindrome("test") << "\n";
    std::cout << std::boolalpha << isPalindrome("tddt") << "\n";
    std::cout << std::boolalpha << isPalindrome("tsdfgergfdst") << "\n";

    return 0;
}