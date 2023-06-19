#include <stdio.h>

int main()
{
  char name[] = "Harry";
  char *ptr = name;
  printf("%c\n", *ptr);
  printf("%c\n", *(ptr + 1));
  printf("%c\n", *(ptr + 2));
  printf("%c\n", *(ptr + 3));
  printf("%c\n", *(ptr + 4));


  printf("%c\n", *name);
  puts(name);
  puts(ptr);

  return 0;
}