#include <stdio.h>
#include <dirent.h>
#include <ctype.h>

int main(void)
{
    int pid;
    char path[100];

    DIR *dir;
    struct dirent *entry;

    printf("Enter PID: ");
    scanf("%d", &pid);

    snprintf(path, sizeof(path), "/proc/%d/task", pid);

    dir = opendir(path);

    if (dir == NULL)
    {
        perror("opendir");
        return 1;
    }

    printf("\nThreads of process %d:\n", pid);

    while ((entry = readdir(dir)) != NULL)
    {
        if (isdigit(entry->d_name[0]))
        {
            printf("Thread ID: %s\n", entry->d_name);
        }
    }

    closedir(dir);

    return 0;
}