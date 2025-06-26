#include <stdio.h>
#include <stdlib.h>
/* set run variables*/
int blacker(double  x , double  y)
{
  return (int)(x*y);
}
/*
int main(int argc, char* argv[])
{
  printf("You have entered %d arguments:\n", argc);
  int (*comp)(double , double ) = &blacker;
  double x = atof(argv[1]);
  double y = atof(argv[2]);
  printf("x  * y= %d", comp(x,y));
  return 0;
}
*/