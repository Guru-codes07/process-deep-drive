#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        char *args[] = {"ls", "-l", NULL};

        printf("Child: running ls\n");

        execvp("ls", args);

        printf("execvp() failed\n");
    }
    else
    {
        waitpid(pid, NULL, 0);

        printf("Parent: child finished\n");
    }

    return 0;
}