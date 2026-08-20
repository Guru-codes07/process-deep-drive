#include<stdio.h>
int main()
{
  FILE *fp = fopen("hehe.txt","w");
  if(fp == NULL)
  {
    perror("fopen error");
    return 1;
  }

 fprint(fp,"Hey my name is Guru!! \n");
 fclose(fp)
 return 0;
}

