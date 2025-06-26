#include <stdio.h>
#include <string.h>
//
// Created by Yogev on 6/11/2025.
//
void main()
{
    int points;

    FILE *fp = fopen("mytext.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        printf("%s", line);
    }


}