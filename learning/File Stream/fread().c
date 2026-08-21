#include <stdio.h>

int main()
{
    FILE *fp;
    char buffer[100];

    fp = fopen("test.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    fread(buffer, sizeof(char), sizeof(buffer) - 1, fp);

    buffer[99] = '\0';

    printf("File content:\n%s\n", buffer);

    fclose(fp);

    return 0;
}
