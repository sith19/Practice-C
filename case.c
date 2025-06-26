#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void upper();
void lower();
/**
int main(int argc, char * argv[])
{

    if (strcmp(argv[0],"upper") == 0)
    {
        upper();
    }else if (strcmp(argv[0],"lower") == 0)
    {
        lower();
    }else
    {
        printf("Wrong command\n");
    }
}**/
void lower()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(tolower(c));
    }
}
void upper()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(toupper(c));
    }
}