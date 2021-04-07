
#include <stdlib.h>
#include <stdio.h>

int main()
{
    struct human
    {
        char name[32];
        int age;
    } *towrite;

    const char filename[] = "saved.dat";
    char *r;
    FILE *fp;

    towrite = (struct human *) malloc(sizeof(struct human) * 1);
    if (towrite == NULL)
    {
        fprintf(stderr, "Unable to allocate structure memory\n");
        exit(1);
    }

    printf("Enter your name: ");
    r = fgets(towrite->name, 32, stdin);
    if (r == NULL)
    {
        fprintf(stderr, "Input error");
        exit(1);
    }

    printf("How old are you: ");
    scanf("%d", &towrite->age);

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to create file %s", filename);
        exit(1);
    }

    fwrite(towrite, sizeof(struct human), 1, fp);
    fclose(fp);

    printf("Data written to %s\n", filename);

    return 0;

}