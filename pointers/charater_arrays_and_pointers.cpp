#include <bits/stdc++.h>

using namespace std;
#define endl  '\n';

void println(char *C)
{
    while (*C != '\0')
    {
        printf("%c", *C);
        C++;
    }
    printf("\n");
}

int main()
{
    char C[6];
    C[0] = 'J', C[1] = 'O', C[2] = 'H', C[3] = 'N', C[4] = '\0', C[5] = 'D';
    println(C);
    printf("%s\n", C);
    printf("size of C = %d\n", sizeof(C));

    char *chars = "HELLO"; // this is not allowing to modify elements in the array
    println(chars);
//    chars[0] = 'W'; this will crash the programme
//    println(chars);

    string s = "JOHN\0D";
    cout << s << endl;
    printf("size of s = %d\n", sizeof(s));

    char *str = "JOHN\0D";
    printf("%s\n", str);
    printf("size of str = %d", sizeof(str));
    return 0;
}