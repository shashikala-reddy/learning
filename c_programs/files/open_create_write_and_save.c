/*Write a C program to create a file and write contents, save and close the file.*/

#include <stdio.h>

int main()
{
    FILE *fp;
    int ch;
    char data[100];
    if((fp=fopen("first","w"))==EOF)
    {
        printf("cant not open file");
        exit(0);
    }
    printf("enter data to write\n");
    fgets(data, 100, stdin);
    fputs(data, fp);
    fclose(fp);
    return 0;
}

