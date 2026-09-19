#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(void)
{
    int pid;

    printf("Enter PID to terminate: ");
    scanf("%d", &pid);

    if (kill(pid, SIGTERM) == 0)
    {
        printf("SIGTERM sent to process %d\n", pid);
    }
    else
    {
        perror("kill");
    }

    return 0;
}