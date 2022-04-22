//
// Created by sajith on 4/22/22.
//

#include<cstdio>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int pid;
    int pids[3];
    int status;
    int num_processes = 0;
    int total_processes = 3;

    while (num_processes < total_processes)
    {
        pid = fork();
        if (pid == 0)
        {
            printf("In child process: process id is %d\n", getpid());
            sleep(5);
            return 4;
        }
    }

    return 0;
}