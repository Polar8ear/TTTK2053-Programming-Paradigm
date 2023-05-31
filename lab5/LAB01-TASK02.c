#include <stdio.h>

//Use enum to make the code more readable
enum Category
{

  FREEZING,

  COLD,

  MODERATE,

  HOT,

  EXTREME

};

double getNumber()
{

  double number;
  int termCount = scanf("%lf", &number);
  while (getchar() != '\n')
    ;

  while (1)
  {
    // Handle Test Case 1: Non-numerical input

    if (termCount == 0)
    {
      // Test Case 1
      printf("Please enter a valid numerical input: ");
    }
    else
    {
      // If no error is found
      return number;
    }

    termCount = scanf("%lf", &number);
    while (getchar() != '\n') //remove unnecessary character in input buffer
      ;
  }
}

int main()
{
  double temp;
  enum Category category;

  printf("Enter the temperature in degrees Celsius: ");
  temp = getNumber();

  if (temp < 0)
  {
    category = FREEZING;
  }
  else if (temp < 10 && temp >= 0)
  {
    category = COLD;
  }
  else if (temp < 25 && temp >= 10)
  {
    category = MODERATE;
  }
  else if (temp < 35 && temp >= 25)
  {
    category = HOT;
  }
  else
  {
    category = EXTREME;
  }

  switch (category)
  {
  case FREEZING:
    printf("The entered temperature is freezing.");

    break;

  case COLD:
    printf("The entered temperature is cold.");
    break;

  case MODERATE:
    printf("The entered temperature is moderate.");
    break;

  case HOT:
    printf("The entered temperature is hot.");
    break;

  case EXTREME:
    printf("The entered temperature is extreme.");
    break;
  }
}