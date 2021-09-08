/*Write a C program to append content to a file*/

#include <stdio.h>

int main()
{
    FILE *fp;
    char a[10];
    char data[100];
    fp=fopen("one","a");
    if(fp==NULL)
    {
        printf("cant not open file") ;
        exit(0);
    }
    printf("enter data to append\n");
    fgets(data,100,stdin);
    int i=0;
  while(data[i]!='\0')
  {
      fputc(data[i],fp);
      i++;
  }
    return 0;
}
