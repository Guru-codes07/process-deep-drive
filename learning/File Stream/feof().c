#include <stdio.h>
int main(void)
{
    FILE *file;
    int ch;
    file = fopen("example.txt", "r");
    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }
    while (1)
    {
        ch = fgetc(file);

        if (feof(file))
        {
            break;
        }

        putchar(ch);
    }
 printf("\n\nEnd of file reached.\n");
 fclose(file);
 return 0;
}
