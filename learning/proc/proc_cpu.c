#include <stdio.h>

int main(void)
{
    int pid;
    char path[100];
    FILE *file;

    unsigned long utime;
    unsigned long stime;

    printf("Enter PID: ");
    scanf("%d", &pid);

    snprintf(path, sizeof(path), "/proc/%d/stat", pid);

    file = fopen(path, "r");

    if (file == NULL)
    {
        perror("fopen");
        return 1;
    }

    fscanf(file,
           "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %lu %lu",
           &utime, &stime);

    printf("User CPU time: %lu\n", utime);
    printf("Kernel CPU time: %lu\n", stime);

    fclose(file);

    return 0;
}
