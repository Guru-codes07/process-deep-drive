#include <stdio.h>
int main(void)
{
    FILE *file;
    char line[100];
    file = fopen("bored.txt", "r");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }
    printf("First read:\n");

    if (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }
    rewind(file);
    printf("\nAfter rewind():\n");

    if (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }
    fclose(file);

    return 0;
}
