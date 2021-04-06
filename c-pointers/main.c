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

void array_pointers()
{
    int a[5] = {10, 11, 12, 13, 14};
    int x;
    int *p;
    p = a;
    for (x = 0; x < 5; ++x)
    {
        printf("%p, %p\n", &a[x], p);
        ++p;
    }

    int *pA = a;
    for (x = 0; x < 5; ++x)
    {
        printf("%d\n", *(pA + x));
    }
}

void allocate_storage()
{
    void *storage;
    storage = malloc(16);

    if (storage == NULL)
    {
        fprintf(stderr, "Allocation failed\n");
    } else
    {
        puts("Memory allocated\n");
    }

    char *chars;
    chars = (char *) malloc(sizeof(char) * 16);
    if (chars == NULL)
    {
        fprintf(stderr, "Allocation failed\n");
    } else
    {
        puts("Memory allocated\n");
    }
}

void malloc_example()
{
    int *storage;
    int x;
    storage = (int *) malloc(sizeof(int) * 5);
    if (storage == NULL)
    {
        fprintf(stderr, "Allocation failed\n");
    } else
    {
        puts("Memory allocated\n");
    }

    for (x = 0; x < 5; ++x)
    {
        printf("%p, %d\n", (storage + x), *(storage + x));
    }
}

void calloc_example()
{
    int *storage;
    int x;

    storage = (int *) calloc(5, sizeof(int));
    if (storage == NULL)
    {
        fprintf(stderr, "Allocation failed\n");
    } else
    {
        puts("Memory allocated\n");
    }
    for (x = 0; x < 5; ++x)
    {
        printf("%p, %d\n", (storage + x), *(storage + x));
    }
}

void realloc_example()
{
    int *storage;
    int x;
    storage = (int *) malloc(sizeof(int) * 5);
    if (storage == NULL)
    {
        fprintf(stderr, "Allocation failed\n");
    } else
    {
        puts("Memory allocated\n");
    }

    for (x = 0; x < 5; ++x)
    {
        printf("%p, %d\n", (storage + x), *(storage + x));
    }

    storage = (int *) realloc(storage, sizeof(int) * 7);
    if (storage == NULL)
    {
        fprintf(stderr, "Reallocation failed\n");
    } else
    {
        puts("Buffer resized\n");
    }

    *(storage + 5) = 55;
    *(storage + 6) = 66;

    for (x = 0; x < 7; ++x)
    {
        printf("%p, %d\n", (storage + x), *(storage + x));
    }

    free(storage);
    storage = NULL;
    puts("Memory freed\n");
}

int main()
{

//    run1();
//    run2();
//    run3();
//    run4();
//    array_pointers();
//    allocate_storage();
//    malloc_example();
//    calloc_example();
    realloc_example();

    return 0;
}