//
// Created by sajith on 4/21/22.
//
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int pid;
    pid = fork();
    int status;

    if (pid == 0)
    {
        system("ps -ef");
        sleep(10);
        system("ps -ef");
        system("ls -al");
        return 3;
    }
    else
    {
        sleep(3);
        wait(&status);
        printf("Status %d %0x\n", status, status);
    }

    return 0;
}