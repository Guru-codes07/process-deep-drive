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
        return 0;
    }
    else
    {
        waitpid(pid, NULL, 0);
        printf("Parent: child process finished\n");
    }

    return 0;
}