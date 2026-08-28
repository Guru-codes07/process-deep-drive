#include <stdio.h>
int main(void)
{
    FILE *file;

    char name[50];
    int age;
    float cgpa;
    file = fopen("guru.txt", "r");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }
    fscanf(file, "%49s %d %f", name, &age, &cgpa);
    printf("Student Details\n");
    printf("----------------\n");
    printf("Name : %s\n", name);
    printf("Age  : %d\n", age);
    printf("CGPA : %.2f\n", cgpa);
    fclose(file);

    return 0;
}
