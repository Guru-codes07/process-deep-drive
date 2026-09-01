#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char *args[] = {"ls", "-l", NULL};

    printf("Running ls using execvp()\n");

    execvp("ls", args);

    printf("execvp() failed\n");

    return 0;
}