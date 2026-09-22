#include <stdio.h>
#include <unistd.h>

unsigned long get_cpu_time(int pid)
{
    char path[100];
    FILE *file;

    unsigned long utime;
    unsigned long stime;

    snprintf(path, sizeof(path), "/proc/%d/stat", pid);

    file = fopen(path, "r");

    if (file == NULL)
        return 0;

    fscanf(file,
           "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %lu %lu",
           &utime, &stime);

    fclose(file);

    return utime + stime;
}

int main(void)
{
    int pid;

    unsigned long cpu1;
    unsigned long cpu2;

    long ticks;
    double usage;

    printf("Enter PID: ");
    scanf("%d", &pid);

    ticks = sysconf(_SC_CLK_TCK);

    cpu1 = get_cpu_time(pid);

    sleep(1);

    cpu2 = get_cpu_time(pid);

    usage = ((double)(cpu2 - cpu1) / ticks) * 100.0;

    printf("\nCPU Usage: %.2f%%\n", usage);

    return 0;
}