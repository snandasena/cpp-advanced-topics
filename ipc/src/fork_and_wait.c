//
// Created by sajith-csi on 6/3/2022.
//

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    int n;
    if (pid == 0)
    {
        n = 1;
    }
    else
    {
        n = 6;
        wait(NULL);
    }

    for (int i = n; i < n + 5; ++i)
    {
        printf("%d\t", i);
        fflush(stdout);
    }

    if (pid != 0)
    {
        printf("\n");
    }

    return 0;
}