#include <stdio.h>

int main(void)
{
    FILE *file;

    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;
    unsigned long iowait;
    unsigned long irq;
    unsigned long softirq;
    unsigned long steal;

    file = fopen("/proc/stat", "r");

    if (file == NULL)
    {
        perror("fopen");
        return 1;
    }

    fscanf(file, "cpu %lu %lu %lu %lu %lu %lu %lu %lu",
           &user,
           &nice,
           &system,
           &idle,
           &iowait,
           &irq,
           &softirq,
           &steal);

    fclose(file);

    printf("System CPU Statistics:\n");

    printf("User:        %lu\n", user);
    printf("Nice:        %lu\n", nice);
    printf("System:      %lu\n", system);
    printf("Idle:        %lu\n", idle);
    printf("I/O Wait:    %lu\n", iowait);
    printf("IRQ:         %lu\n", irq);
    printf("Soft IRQ:    %lu\n", softirq);
    printf("Steal:       %lu\n", steal);

    return 0;
}