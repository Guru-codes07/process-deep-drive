#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        printf("Child process\n");
    }
    else
    {
        wait(NULL);
        printf("Parent process\n");
    }

    return 0;
}
