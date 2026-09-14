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

    dir = opendir("/proc");

    if (dir == NULL)
    {
        perror("opendir");
        return 1;
    }

    printf("PID\tNAME\t\tMEMORY\n");

    while ((entry = readdir(dir)) != NULL)
    {
        if (!isdigit(entry->d_name[0]))
            continue;

        snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);

        file = fopen(path, "r");

        if (file == NULL)
            continue;

        char name[100] = "Unknown";
        char memory[100] = "Unknown";

        while (fgets(line, sizeof(line), file) != NULL)
        {
            if (strncmp(line, "Name:", 5) == 0)
            {
                sscanf(line, "Name:\t%s", name);
            }

            if (strncmp(line, "VmRSS:", 6) == 0)
            {
                sscanf(line, "VmRSS:\t%[^\n]", memory);
            }
        }

        fclose(file);

        printf("%s\t%-15s\t%s\n",
               entry->d_name,
               name,
               memory);
    }

    closedir(dir);

    return 0;
}
