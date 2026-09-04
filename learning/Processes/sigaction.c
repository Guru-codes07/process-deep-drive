#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig)
{
    printf("Signal received: %d\n", sig);
}

int main(void)
{
    struct sigaction action;

    action.sa_handler = handle_signal;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    sigaction(SIGINT, &action, NULL);

    printf("Press Ctrl+C to send SIGINT\n");

    while (1)
    {
        sleep(1);
    }

    return 0;
}