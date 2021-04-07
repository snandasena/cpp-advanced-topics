#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void access_buffer()
{
    int *base, *p, x;

    base = (int *) malloc(sizeof(int) * 10);

    if (base == NULL)
    {
        fprintf(stderr, "Allocation failure\n");
    } else
    {
        puts("Memory allocared\n");
    }

    // retain the base
    p = base;
    for (x = 0; x < 10; ++x)
    {
        *p = x * 100;
        p++;
    }
    puts("Memory allocated and filled\n");

    p = base;
    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", *p);
        p++;
    }
}

void access_buffer2()
{
    int *p, x;

    p = (int *) malloc(sizeof(int) * 10);

    if (p == NULL)
    {
        fprintf(stderr, "Allocation failure\n");
    } else
    {
        puts("Memory allocared\n");
    }


    for (x = 0; x < 10; ++x)
    {
        *(p + x) = x * 100;
    }
    puts("Memory allocated and filled\n");

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", *p);
        p++;
    }
}

void struct_pointers()
{
    struct person
    {
        char *name;
        int *age;
    } my;

    char n[] = "Jeniffer";

    my.age = (int *) malloc(sizeof(int) * 1);

    if (my.age == NULL)
    {
        fprintf(stderr, "Allocation error\n");
    }

    *my.age = 26;
    my.name = n;

    printf("%s is %d years old\n", my.name, *my.age);
}

void create_struct_pointers()
{
    struct person
    {
        char name[32];
        int age;
    } president = {
            "George Washington",
            53
    };

    struct person *first;
    printf("%s is %d years old\n",
           president.name,
           president.age);

    first = &president;
    printf("%s is %d years old\n",
           first->name,
           first->age);

}

void allocate_structure_memory()
{
    struct person
    {
        char name[32];
        int age;
    } *first;


    first = (struct person *) malloc(sizeof(struct person) * 1);

    if (first == NULL)
    {
        fprintf(stderr, "Unable to allocate memory");
    }

    strcpy(first->name, "George Washington");
    printf("How old was %s?\n", first->name);

    first->age = 59;

    printf("%s was %d years old\n",
           first->name,
           first->age);

}

void save_pointers()
{
    int *base, x;
    FILE *fp;

    base = (int *) malloc(sizeof(int) * 10);

    if (base == NULL)
    {
        fprintf(stderr, "Allocation failure\n");
    }

    for (x = 0; x < 10; ++x)
    {
        *(base + x) = x * 100;
    }

    puts("Memory allocated and filled\n");

    fp = fopen("integers.dat", "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to create a file\n");
    }

    fwrite(base, sizeof(int), 10, fp);
    puts("Data saved!");
}

void read_pointers()
{
//    save_pointers();
    int *base, r, x;
    FILE *fp;
    base = (int *) malloc(sizeof(int) * 10);
    if (base == NULL)
    {
        fprintf(stderr, "Allocation failure\n");
    }

    fp = fopen("integers.dat", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to read a file\n");
    }
    r = fread(base, sizeof(int), 10, fp);
    if (r != 10)
    {
        fprintf(stderr, "File read error\n");
    }
    puts("Data read\n");

    fclose(fp);
    puts("Values: ");

    for (x = 0; x < 10; ++x)
    {
        printf("%d\n", *(base + x));
    }
}


void save_struct_pointers()
{
    struct human
    {
        char *name;
        int age;
    } *towrite;
    const char filename[] = "saved.dat";
    char *r;
    FILE *fp;
    towrite = (struct human *) malloc(sizeof(struct human));

    if (towrite == NULL)
    {
        fprintf(stderr, "Unable to allocate structure memory\n");
        exit(1);
    }

    towrite->name = (char *) malloc(sizeof(char) * 32);
    if (towrite->name == NULL)
    {
        fprintf(stderr, "Unable to allocate structure memory\n");
        exit(1);
    }
    printf("Enter your name: ");
    r = fgets(towrite->name, 32, stdin);
    if (r == NULL)
    {
        fprintf(stderr, "Input error\n");
        exit(1);
    }

    printf("How old are you: ");
    scanf("%d", &towrite->age);

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to create a file\n");
        exit(1);
    }

    fwrite(towrite, sizeof(struct human), 1, fp);
    fclose(fp);
    printf("Data written to %s\n", filename);
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
//    realloc_example();
//    access_buffer();
//    access_buffer2();
//    struct_pointers();
//    create_struct_pointers();
//    allocate_structure_memory();
//    save_pointers();
//    read_pointers();
    save_struct_pointers();
    return 0;
}