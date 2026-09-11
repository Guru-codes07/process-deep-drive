#include <stdio.h>

int main(void)
{
    int pid;
    char path[100];
    char line[256];
    FILE *file;

    printf("Enter PID: ");
    scanf("%d", &pid);

    snprintf(path, sizeof(path), "/proc/%d/status", pid);

    file = fopen(path, "r");

    if (file == NULL)
    {
        perror("fopen");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "VmSize:%[^\n]", line) == 1)
        {
            printf("Virtual Memory: %s\n", line);
        }

        if (sscanf(line, "VmRSS:%[^\n]", line) == 1)
        {
            printf("Physical Memory: %s\n", line);
        }
    }

    fclose(file);

    return 0;
}
