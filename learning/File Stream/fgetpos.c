#include <stdio.h>
int main(void)
{
    FILE *file;
    fpos_t position;
    int ch;
    file = fopen("hmmm.txt", "r");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }
    printf("Characters read: ");

    for (int i = 0; i < 5; i++)
    {
        ch = fgetc(file);
        putchar(ch);
    }
    if (fgetpos(file, &position) != 0)
    {
        printf("\nUnable to get file position.\n");
        fclose(file);
        return 1;
    }

    printf("\nFile position has been saved.\n");
    ch = fgetc(file);
    printf("Next character: %c\n", ch);
    fclose(file);
    return 0;
}
