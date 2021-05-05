//
// Created by sajith on 5/5/21.
//

#include<iostream>
#include<string>

using namespace std;

void reverse_string(string *text)
{
    int len = text->length();
    for (int i = 0; i < len / 2; ++i)
    {
        char temp = text->at(len - 1 - i);
        text->at(len - 1 - i) = text->at(i);
        text->at(i) = temp;
    }

}

int main()
{
    string text = "hello";
    reverse_string(&text);
    cout << text << endl;

    return 0;
}