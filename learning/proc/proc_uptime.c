#include <stdio.h>

int main(void)
{
    FILE *file;
    double uptime;
    double idle_time;

    file = fopen("/proc/uptime", "r");

    if (file == NULL)
    {
        perror("fopen");
        return 1;
    }

    fscanf(file, "%lf %lf", &uptime, &idle_time);

    fclose(file);

    printf("System uptime: %.2f seconds\n", uptime);

    return 0;
}