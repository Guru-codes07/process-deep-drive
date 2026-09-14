#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    DIR *dir;
    struct dirent *entry;

    char path[100];
    char line[256];

    FILE *file;

    int pid;
    int ppid;
    char name[100];

    dir = opendir("/proc");

    if (dir == NULL)
    {
        perror("opendir");
        return 1;
    }

    printf("PID\tPPID\tNAME\n");
 while ((entry = readdir(dir)) != NULL)
    {
        if (!isdigit(entry->d_name[0]))
            continue;

        pid = 0;
        ppid = 0;
        strcpy(name, "Unknown");

        snprintf(path, sizeof(path),
                 "/proc/%s/status", entry->d_name);

        file = fopen(path, "r");

        if (file == NULL)
            continue;

        while (fgets(line, sizeof(line), file) != NULL)
        {
            if (strncmp(line, "Name:", 5) == 0)
            {
                sscanf(line, "Name:\t%99s", name);
            }

            if (strncmp(line, "Pid:", 4) == 0)
            {
                sscanf(line, "Pid:\t%d", &pid);
            }

            if (strncmp(line, "PPid:", 5) == 0)
            {
                sscanf(line, "PPid:\t%d", &ppid);
            }
        }

        fclose(file);

        printf("%d\t%d\t%s\n", pid, ppid, name);
    }

    closedir(dir);

    return 0;
}
