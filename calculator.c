#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAXOP 100
#define MAXVAL 100
#define BUFFSIZE 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);
double peek(void);
void duplicate(void);
void swap(void);
/*int main(void)
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF)
  {
    switch (type)
    {
    case NUMBER:
      push(atof(s));
      break;

    case '+':
      push(pop() + pop());
      break;

    case '-':
      op2 = pop();
      push(pop() - op2);
      break;

    case '*':
      push(pop() * pop());
      break;

    case '/':
      op2 = pop();

      if (op2 != 0.0)
      {
        push(pop() / op2);
      }
      else
      {
        printf("Error: zero divisor.\n");
      }
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0)
      {
        push((int)pop() %  (int)op2);
      }else
      {
        printf("Error: zero divisor.\n");
      }
      break;
    case 's':

      push(sin(pop()));
      break;
    case 'e':
      push(exp(pop()));
    case 'p':
      op2 = pop();
      push(pow(pop(), op2));
      break;


    case '\n':
      printf("result: %.8g\n", pop());
      break;

    default:
      printf("Error: unknown command %s.\n", s);
      break;
    }
  }

  return 0;
}*/

static int sp = 0;
double val[MAXVAL];
double peek()
{
  if (sp < 0)
  {
    printf("Error: stack empty.\n");
    return -1;
  }
  return val[sp - 1];
}
void duplicate()
{
  const double temp = peek();
  push(temp);
}
void swap()
{
  const double temp = val[sp - 2];
  val[sp - 2] = val[sp - 1 ];
  val[sp - 1] = temp;

}
void clear()
{
  while (sp > 0)
  {
    val[--sp] = 0.0;
  }
  sp = 0;
}
void push(double f)
{
  if (sp < MAXVAL)
  {
    val[sp++] = f;
  }
  else
  {
    printf("Error: stack full, can't push %g.\n", f);
  }
}

double pop(void)
{
  if (sp > 0)
  {
    return val[sp - 1];
  }
  else
  {
    printf("Error: stack empty.\n");
    return 0.0;
  }
}

int bufp = 0;
char buf[BUFFSIZE];

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFFSIZE)
  {
    printf("ungetch: too many characters\n");
  }
  else
  {
    buf[bufp++] = c;
  }
}

int getop(char s[])
{
  int i = 0, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  if (!isdigit(c) && c != '.' && c != '-')
  {
    return c;
  }

  if (c == '-')
  {
    int next = getch();
    if (next == '\n' || next == ' ' || next == '\t')
    {
      ungetch(next);
      return c; // return '-' as operator
    }
    else if (!isdigit(next) && next != '.')
    {
      return next; // not a number
    }
    else // number like "-5", "-.6" etc, next is digit or '.'
    {
      s[++i] = c = next;
    }
  }
  else
  {
    c = getch();
  }

  if (isdigit(c))
  {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  if (c == '.')
  {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  if (c != EOF)
  {
    ungetch(c);
  }

  return NUMBER;
}

