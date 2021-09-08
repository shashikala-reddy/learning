/*Write a C program to append content to a file.*/

#include <stdio.h>

int main()
{
    FILE *fp;
    char a[10];
    fp=fopen("one","a");
    if(fp==NULL)
    {
        printf("cant not open file") ;
        exit(0);
    }
    printf("enter data to append\n");
    scanf("%s",a);
    int i=0;
  while(a[i]!='\0')
  {
      fputc(a[i],fp);
      i++;
  }
    return 0;
}
