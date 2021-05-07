#include <stdio.h>

typedef struct test
{
    int data;
} T;

struct test get_test()
{
    T t;
    t.data = 10;
    return t;
}

int main()
{
    T t = get_test();
    printf("hello %d", t.data);
    return 0;
}

