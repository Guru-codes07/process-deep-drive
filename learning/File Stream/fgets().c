#include <stdio.h>
int main(void)
{
    FILE *file;
    char line[100];
    file = fopen("hehehe.txt", "r");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }
    if (fgets(line, sizeof(line), file) != NULL)
    {
        printf("Line read from file:\n");
        printf("%s", line);
    }

    fclose(file);

    return 0;
}
