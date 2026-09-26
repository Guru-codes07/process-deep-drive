#include <stdio.h>

int main(void)
{
    FILE *file;

    double load1;
    double load5;
    double load15;

    int running;
    int total;
    int last_pid;

    file = fopen("/proc/loadavg", "r");

    if (file == NULL)
    {
        perror("fopen");
        return 1;
    }

    fscanf(file, "%lf %lf %lf %d/%d %d",
           &load1,
           &load5,
           &load15,
           &running,
           &total,
           &last_pid);

    fclose(file);

    printf("System Load Average:\n");
    printf("1 minute:  %.2f\n", load1);
    printf("5 minutes: %.2f\n", load5);
    printf("15 minutes: %.2f\n", load15);

    printf("\nRunning processes: %d\n", running);
    printf("Total processes:   %d\n", total);
    printf("Last PID created:  %d\n", last_pid);

    return 0;
}