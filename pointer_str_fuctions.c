#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * strcata(char *s, char *t);
int strend(char *s, char *t);
void reverse1(char *s);
/*void main()
{
    char str[] = "anas";
    char *add = "\tman";
    char * man = "man";
    char * bat = "bat";
    char *n = strcata(bat,man);
    printf("hi my name is %s\n",n);
    int n2 = strend(n,"big");
    printf("hi my name is %d\n",n2);
    reverse1(str);
    printf("hi my name is %s\n",str);

}*/

char* strcata(char* s, char* t)
{
    char* p = malloc (strlen(s) + strlen(t) - 1);
    char *l = p;
    while (*s != '\0')
    {
        *l++ = *s++;
    }
    while (*t != '\0' )
    {
        *l++ = *t++;
    }
    *l = '\0';
    return p;



}
int strend(char* s, char* t)
{
    int l =0;
    int len = strlen(t);
    s += strlen(s) - 1;
    t += strlen(t) - 1;
    while (*s-- == *t--)
    {
        l++;
    }

    if (l != len)
    {
        return 0;
    }
    return 1;
}
void reverse1(char *s)
{
    char *t = s + strlen(s)-1;
    while (s < t)
    {
        char temp = *s;
        *s = *t;
        *t = temp;
        t--;
        s++;
    }

}