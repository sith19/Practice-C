#include <stdio.h>
#include <string.h>
void compareFiles(const char * file1, const char * file2);
/**void main()
{
    compareFiles("input.txt", "input1.txt");
}**/
void compareFiles(const char *file1, const char *file2)
{
    FILE *fp = fopen(file1, "r");
    FILE *fp1 = fopen(file2, "r");

    if (fp == NULL || fp1 == NULL)
    {
        printf("Error opening one of the files.\n");
        return;
    }

    char line1[256], line2[256];
    int lineNum = 1;

    while (fgets(line1, sizeof(line1), fp) && fgets(line2, sizeof(line2), fp1))
    {
        if (strcmp(line1, line2) != 0)
        {
            printf("Files differ at line %d:\n", lineNum);
            printf("File1: %s ", line1);
            printf("File2: %s", line2);
            fclose(fp);
            fclose(fp1);
            return;
        }
        lineNum++;
    }

    if (fgets(line1, sizeof(line1), fp) || fgets(line2, sizeof(line2), fp1))
    {
        printf("Files differ in length at line %d.\n", lineNum);
    }
    else
    {
        printf("Files are the same.\n");
    }

    fclose(fp);
    fclose(fp1);
}