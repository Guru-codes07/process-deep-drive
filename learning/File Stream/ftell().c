#include <stdio.h>
int main(void)
{
    FILE *file;
    char ch;
    long position;

   
    file = fopen("example.txt", "r");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    
    ch = fgetc(file);

    position = ftell(file);

    printf("Character read: %c\n", ch);
    printf("Current file position: %ld\n", position);

    ch = fgetc(file);

    position = ftell(file);

    printf("Character read: %c\n", ch);
    printf("Current file position: %ld\n", position);
    fclose(file);

    return 0;
}
