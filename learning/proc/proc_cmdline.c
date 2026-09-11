#include <stdio.h>

int main(void)
{
    int pid;
    char path[100];
    char command[256];
    FILE *file;

    printf("Enter PID: ");
    scanf("%d", &pid);

    snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);

    file = fopen(path, "r");

    if (file == NULL)
    {
        perror("fopen");
        return 1;
    }

    while (fgets(command, sizeof(command), file) != NULL)
    {
        printf("Command: %s\n", command);
    }

    fclose(file);

    return 0;
}
