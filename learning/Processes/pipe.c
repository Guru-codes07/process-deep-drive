#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd[2];
    char message[] = "Hello from parent";
    char buffer[50];

    pipe(fd);

    if (fork() == 0)
    {
        close(fd[1]);

        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        close(fd[0]);
    }
    else
    {
        close(fd[0]);

        write(fd[1], message, strlen(message) + 1);

        close(fd[1]);
    }

    return 0;
}