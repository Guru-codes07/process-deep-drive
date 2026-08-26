#include <stdio.h>
int main(void)
{
    FILE *file;
    file = fopen("angry.txt", "w");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }
    fputc('H', file);
    fputc('e', file);
    fputc('l', file);
    fputc('l', file);
    fputc('o', file);
    fputc('\n', file);

    printf("Characters written successfully.\n");
    fclose(file);

    return 0;
}
