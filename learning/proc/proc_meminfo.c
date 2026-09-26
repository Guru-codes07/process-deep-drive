#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file;
    char line[256];

    unsigned long total = 0;
    unsigned long free_mem = 0;
    unsigned long available = 0;

    file = fopen("/proc/meminfo", "r");

    if (file == NULL)
    {
        perror("fopen");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "MemTotal: %lu kB", &total) == 1)
            continue;

        if (sscanf(line, "MemFree: %lu kB", &free_mem) == 1)
            continue;

        if (sscanf(line, "MemAvailable: %lu kB", &available) == 1)
            continue;
    }

    fclose(file);

    printf("Memory Information:\n");

    printf("Total RAM:     %lu kB\n", total);
    printf("Free RAM:      %lu kB\n", free_mem);
    printf("Available RAM: %lu kB\n", available);

    return 0;
}