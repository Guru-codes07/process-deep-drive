#include <stdio.h>
#include <unistd.h>
int main(void)
{
    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        printf("Child process\n");
    }
    else if (pid > 0)
    {
        printf("Parent process\n");
    }
    else
    {
        printf("fork() failed\n");
    }

    return 0;
}
