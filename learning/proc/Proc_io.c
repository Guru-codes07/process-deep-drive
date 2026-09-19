#include <stdio.h>

int main(void)
{
    int pid;
    char path[100];
    char line[256];
    FILE *file;

    printf("Enter PID: ");
    scanf("%d", &pid);

    snprintf(path, sizeof(path), "/proc/%d/io", pid);

    file = fopen(path, "r");

    if (file == NULL)
    {
        perror("fopen");
        return 1;
    }

    printf("\nI/O information for PID %d:\n", pid);

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}