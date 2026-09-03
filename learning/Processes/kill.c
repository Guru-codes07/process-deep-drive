#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
    printf("Sending SIGTERM to myself...\n");

    kill(getpid(), SIGTERM);

    printf("This will not be printed\n");

    return 0;
}