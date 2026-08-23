#include <stdio.h>
int main(void)
{
    FILE *file;
    int ch;
    file = fopen("huhhh.txt", "r");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }
    if (ferror(file))
    {
        printf("\nError occurred while reading the file.\n");
    }
    else
    {
        printf("\nFile read successfully.\n");
    }
    fclose(file);
    return 0;
}
