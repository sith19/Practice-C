#include <stdio.h>
#include <string.h>

void reverse();
/*void main()
{

    char str[] = "apple";
    reverse(str);
    printf("%s\n", str);
}*/
void reverseHelper(char s[], int i, int j)
{
    if (j == 0)
    {
        return;
    }
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    reverseHelper(s, ++i, --j);
}
void reverse(char s[])
{
    reverseHelper(s, 0, strlen(s) - 1);
}