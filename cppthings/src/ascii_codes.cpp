//
// Created by sajith on 11/11/21.
//

#include <iostream>

using namespace std;

int main()
{
    unsigned a = 0xFFFF;
    cout << a << endl;


    char name[10] = {'J', 'o', 'h', 'n', '\0'};
    printf("%li\n", sizeof(name));
    printf("%s\n", name);
//    char *pName = {'J', 'o', 'h', 'n'}; ERROR
//    printf("%S", pName);

    char namefrominput[10];
    scanf("%s", namefrominput);

    printf("%s", namefrominput);

    return 0;
}