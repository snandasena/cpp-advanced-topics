
#include <stdlib.h>
#include <stdio.h>

int main()
{
    struct human
    {
        char name[32];
        int age;
    } *toread;

    const char filename[] = "saved.dat";
    FILE *fp;

    toread = (struct human *) malloc(sizeof(struct human) * 1);
    if (toread == NULL)
    {
        fprintf(stderr, "Unable to allocate structure memory\n");
        exit(1);
    }

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to reade file: %s", filename);
        exit(1);
    }

    fread(toread, sizeof(struct human), 1, fp);

    fclose(fp);

    puts("Data read: ");
    printf("Name: %sAge:%d",
           toread->name,
           toread->age);

    return 0;

}