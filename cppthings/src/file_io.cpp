//
// Created by sajith on 6/29/21.
//

#include <cstdio>

constexpr int maxString = 1024;
constexpr int repeat = 5;

int main()
{
    const char *fn = "testfile.txt";
    const char *str = "This is a literal c-string.\n";

    puts("waiting file");

    // create/write the file
    FILE *fw = fopen(fn, "w");
    for (int i = 0; i < repeat; ++i)
    {
        fputs(str, fw);
    }

    fclose(fw);
    puts("done!");

    // read  the file
    FILE *fr = fopen(fn, "r");
    char buf[maxString];

    while (fgets(buf, maxString, fr))
    {
        fputs(buf, stdout);
    }

    fclose(fr);
    remove(fn);

    puts("done");
    return 0;
}

