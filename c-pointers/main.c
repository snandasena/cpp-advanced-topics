#include <stdio.h>
#include <stdlib.h>

void set(int *a, int *b)
{
    *a = 100;
    *b = 200;
}

void run1()
{
    int age;
    int *pAge;

    pAge = &age;
    scanf("%d", pAge);
    printf("%d\n", age);
    printf("%d\n", *pAge);

}

void run2()
{
    int a, b;
    set(&a, &b);
    printf("A: %d, B: %d", a, b);

    int x, y;
    int *pX, *pY;
    pX = &x;
    pY = &y;
    set(pX, pY);
    printf("\n");
    printf("X: %d, Y: %d", x, y);
}

int *iptr(void)
{
    static int a = 53;
    return (&a);
}

void run3()
{
    int *x;
    x = iptr();

    if (x == NULL)
    {
        fprintf(stderr, "Memory error\n");
        exit(1);
    }

    printf("The address return is %p\n", x);
    printf("The value return is %d\n", *x);

}

void run4()
{
    void *chunk;
    chunk = malloc(1024);
    if (chunk == NULL)
    {
        puts("Memory allocation failed\n");
    } else
    {
        printf("1024 bytes allocated at %p\n", chunk);
        free(chunk);
    }
}

int main()
{

//    run1();
//    run2();
//    run3();
    run4();
    return 0;
}