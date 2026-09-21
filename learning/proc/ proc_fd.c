#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

int main(void)
{
    int pid;
    char path[100];
    char link_path[100];
    char target[256];

    DIR *dir;
    struct dirent *entry;

    printf("Enter PID: ");
    scanf("%d", &pid);

    snprintf(path, sizeof(path), "/proc/%d/fd", pid);

    dir = opendir(path);

    if (dir == NULL)
    {
        perror("opendir");
        return 1;
    }

    printf("\nOpen file descriptors for PID %d\n",pid);

    while ((entry = readdir(dir)) != NULL)
    {
        if (!isdigit(entry->d_name[0]))
            continue;

        snprintf(link_path, sizeof(link_path),
                 "/proc/%d/fd/%s", pid, entry->d_name);

        ssize_t size = readlink(link_path, target, sizeof(target) - 1);

        if (size != -1)
        {
            target[size] = '\0';

            printf("FD %s -> %s\n",
                   entry->d_name, target);
        }
    }

    closedir(dir);

    return 0;
}