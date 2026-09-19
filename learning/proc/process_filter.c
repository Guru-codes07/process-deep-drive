#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    DIR *dir;
    struct dirent *entry;

    char target[100];
    char path[100];
    char line[256];
    char name[100];

    FILE *file;

    printf("Enter process name: ");
    scanf("%99s", target);

    dir = opendir("/proc");

    if (dir == NULL)
    {
        perror("opendir");
        return 1;
    }

    printf("\nMatching processes:\n");

    while ((entry = readdir(dir)) != NULL)
    {
        if (!isdigit(entry->d_name[0]))
            continue;

        snprintf(path, sizeof(path),
                 "/proc/%s/status", entry->d_name);

        file = fopen(path, "r");

        if (file == NULL)
            continue;

        strcpy(name, "Unknown");

        while (fgets(line, sizeof(line), file) != NULL)
        {
            if (strncmp(line, "Name:", 5) == 0)
            {
                sscanf(line, "Name:\t%99s", name);
                break;
            }
        }

        fclose(file);

        if (strcmp(name, target) == 0)
        {
            printf("PID: %s\tName: %s\n",
                   entry->d_name, name);
        }
    }

    closedir(dir);

    return 0;
}
