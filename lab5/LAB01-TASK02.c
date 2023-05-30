#include <stdio.h>

int main()
{
  double temp;
  int category;

  scanf("%lf", &temp);

  if (temp < 0)
  {
    category = 0;
  }
  else if (temp < 10 && temp >= 0)
  {
    category = 1;
  }
  else if (temp < 25 && temp >= 11)
  {
    category = 2;
  }
  else if (temp < 35 && temp >= 26)
  {
    category = 3;
  }
  else
  {
    category = 4;
  }

  switch (category)
  {
  case 0:
    printf("Freezing");
    break;

  case 1:
    printf("Cold");
    break;

  case 2:
    printf("Moderate");
    break;

  case 3:
    printf("Hot");
    break;

  case 4:
    printf("Extreme");
    break;
  }
}