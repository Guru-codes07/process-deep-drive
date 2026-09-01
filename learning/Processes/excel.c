#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("Running ls using execl()\n");

    execl("/bin/ls", "ls", "-l", NULL);

    printf("execl() failed\n");

    return 0;
}