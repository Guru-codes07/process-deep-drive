#include <stdio.h>
int main(void)
{
    FILE *file;
    file = fopen("buhahahaha.txt", "w");
   if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }
    fputs("Hello World!\n", file);
    fputs("This is a simple C program.\n", file);
    fputs("Learning file handling is fun!\n", file);

    printf("Strings written successfully.\n");
    fclose(file);

    return 0;
}
