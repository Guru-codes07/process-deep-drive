#include <stdio.h>

int main(void)
{
    FILE *file;
    int numbers[] = {10, 20, 30, 40, 50};

    file = fopen("numbers.dat", "wb");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

 
    size_t written = fwrite(numbers, sizeof(int), 5, file);

    if (written == 5)
    {
        printf("Data written successfully.\n");
    }
    else
    {
        printf("Error writing data.\n");
    }

    fclose(file);

    return 0;
}
