
/*
 * This code is only working in clang compiler
 *
 * Running instructions
 *
 * clang c_asm.c
 * ./a.out
 */

#include <stdio.h>

int total;

int main()
{
    int x;
    total = 1;
    for (x = 0; x < 10; x++)
    {
        printf("%d\n", total);
        asm(
        ".intel_syntax noprefix;"
        "mov rax, total;"
        "imul rax, 2;"
        "mov total, rax;"
        );
    }

    return 0;
}