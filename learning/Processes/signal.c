#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig)
{
    printf("Signal received: %d\n", sig);
}

int main(void)
{
    signal(SIGINT, handle_signal);

    printf("Press Ctrl+C to send SIGINT\n");

    while (1)
    {
        sleep(1);
    }

    return 0;
}