#include <stdio.h>
int main(void)
{
    FILE *file;
    char ch;

    /* Open file */
    file = fopen("bruhh.txt", "r");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    /* Move file pointer to the 5th character */
    fseek(file, 4, SEEK_SET);

    /* Read character */
    ch = fgetc(file);

    printf("Character at position 5: %c\n", ch);

    /* Close file */
    fclose(file);

    return 0;
}
