#include <stdio.h>

void show_file(const char *path)
{
    FILE *file;
    char line[256];

    file = fopen(path, "r");

    if (file == NULL)
    {
        perror(path);
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);
}

int main(void)
{
    printf(" MEMORY (/proc/meminfo) \n");
    show_file("/proc/meminfo");

    printf("\n LOAD (/proc/loadavg) \n");
    show_file("/proc/loadavg");

    printf("\n CPU (/proc/stat) \n");
    show_file("/proc/stat");

    return 0;
}