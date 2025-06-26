
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int htoi(const char s[])
{
    int total = 0;
    int common = 1;
    for(int i = ((int)strlen(s) -1) ; i >= 0; i--)
    {
        if (i == 0 || i == 1)
        {

        }else if (s[i] >= 49 && s[i] <= 57)
        {
            total += (s[i] - 48) * common;
        }else if (s[i] >= 'A' && s[i] <= 'F')
        {
            total += (s[i] - 55) * common;
        }else
        {
            printf("%s is not a Hex number", s);
            return -1;
        }
        if (i >= 2)
        {
            common *= 16;
        }
    }
    return total;
}

/*void main()
{
   const char s[] = "0x4E5B1";
   printf("%d is the decimal value", htoi(s));
}*/
