#include <stdio.h>
#include <dirent.h>
#include <ctype.h>

int main(void)
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");

    if (dir == NULL)
    {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (isdigit(entry->d_name[0]))
        {
            printf("PID: %s\n", entry->d_name);
        }
    }

    closedir(dir);

    return 0;
}
