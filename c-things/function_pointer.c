#include <stdio.h>

typedef void (*voidReturnType)(const char *);

void voidReturn(const char *message)
{
    printf("voidReturn: %s\n", message);
}

int intReturn(const char *message)
{
    printf("intReturn: %s\n", message);
    return 1;
}

void voidReturnTypeNoParam()
{
    printf("voidReturnTypeNoParam");
}

void callFunction(const voidReturnType *func, size_t size)
{
    size_t current = 0;
    while (current < size)
    {
        func[current]("hello world");
        current++;
    }
}


int main()
{
    voidReturnType functionList[3];
    functionList[0] = voidReturn;
    functionList[1] = (voidReturnType) (intReturn); // breaks in emscripten
    functionList[2] = (voidReturnType) (voidReturnTypeNoParam); // breaks in emscripten

    callFunction(functionList, 3);
    return 0;
}