#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("Before exec()\n");

    execl("/bin/ls", "ls", NULL);

    printf("After exec()\n");

    return 0;
}#include<stdio.h>