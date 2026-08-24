#include <stdio.h>
int main(void)
{
    FILE *file;
    fpos_t position;
    int ch;
    file = fopen("ehhhh.txt", "r");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }
    printf("First 5 characters: ");

    for (int i = 0; i < 5; i++)
    {
        ch = fgetc(file);
        putchar(ch);
    }

    printf("\n");
    if (fgetpos(file, &position) != 0)
    {
        printf("Unable to save file position.\n");
        fclose(file);
        return 1;
    }

    printf("File position saved.\n");
    printf("Next 3 characters: ");

    for (int i = 0; i < 3; i++)
    {
        ch = fgetc(file);
        putchar(ch);
    }

    printf("\n");
    if (fsetpos(file, &position) != 0)
    {
        printf("Unable to restore file position.\n");
        fclose(file);
        return 1;
    }

    printf("File position restored.\n");
    printf("Reading again: ");

    for (int i = 0; i < 3; i++)
    {
        ch = fgetc(file);
        putchar(ch);
    }

    printf("\n");
    fclose(file);

    return 0;
}
