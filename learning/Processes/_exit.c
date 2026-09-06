#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("Before _exit()\n");

    _exit(0);

    printf("After _exit()\n");

    return 0;
}