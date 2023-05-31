#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALLOWED_AGE 117

// A struct that's like a class to structure date better
struct Date
{
  int day;
  int month;
  int year;
};

// A helper function to get whole line of input
int getWholeLine(char *text)
{
  scanf("%[^\t\n]s", text);
  while (getchar() != '\n')
    ;
  return 0;
}

// A function to validate birthdate's day, month and year.
// - checks if the month is valid
// - checks if the day is valid in the respective month
int validateBirthdate(struct Date birthdate, struct Date currentDate)
{

  int isLeapYear = (birthdate.year % 4 == 0) && ((birthdate.year % 400 == 0) || (birthdate.year % 100 != 0));
  int maxDays = 31;
  switch (birthdate.month)
  {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    break;

  case 2:
    maxDays = isLeapYear ? 29 : 28;
    break;

  case 4:
  case 6:
  case 9:
  case 11:
    maxDays = 30;
    break;

  default:
    printf("Please enter a valid month\n");
    return 1;
  }

  if (birthdate.day < 0)
  {
    printf("Please enter a valid day that is larger than 0\n");
    return 1;
  }

  if (birthdate.day > maxDays)
  {
    printf("Please enter a valid day that is less than %d days\n", maxDays);
    return 1;
  }

  if(currentDate.year - birthdate.year > MAX_ALLOWED_AGE) {
    printf("You should sign up for guinness world records and I'll update the max allowed age.");
    return 1;
  }

  if (birthdate.year > currentDate.year)
  {
    printf("Please enter a date that is not a date with future year.\n");
    return 1;
  }

  if (birthdate.year == currentDate.year)
  {
    if (birthdate.month > currentDate.month)
    {
      printf("Please enter a date that is not a future date.\n");
      return 1;
    }

    if (birthdate.month == currentDate.month)
    {
      if (birthdate.day > currentDate.day)
      {
        printf("Please enter a date that is not a future date.\n");
        return 1;
      }
    }
  }

  if (birthdate.month == currentDate.month && birthdate.day == currentDate.day)
  {
    printf("Happy Birthday!\n");
  }

  return 0;
}

int calculateAge(struct Date birthdate, struct Date currentDate)
{
  int age = currentDate.year - birthdate.year;

  // Since there's nothing left to be deducted
  if (age <= 0)
  {
    return 0;
  }

  // if the person hasn't passed the birthday month
  if (currentDate.month > birthdate.month)
  {
    return age - 1;
  }

  // if now is the birthdaymonth, we will deduct if he hasnt passed birthday.
  if (currentDate.month == birthdate.month && currentDate.day < birthdate.day)
  {
    return age - 1;
  }

  return age;
}

int generateId()
{
  srand(time(0));

  return rand() % 10000;
}

int main()
{
  char name[256];
  char department[256];
  char birthdateString[10];

  printf("Enter name: ");
  getWholeLine(name);

  printf("Enter department: ");
  getWholeLine(department);

  time_t my_time;
  struct tm *timeinfo;
  time(&my_time);
  timeinfo = localtime(&my_time);

  struct Date currentDate;
  currentDate.year = timeinfo->tm_year + 1900;
  currentDate.month = timeinfo->tm_mon + 1;
  currentDate.day = timeinfo->tm_mday;

  int day, month, year;
  struct Date birthdate;

  do
  {
    printf("Enter birthdate (day month year): ");
    getWholeLine(birthdateString);
    sscanf(birthdateString, "%d %d %d", &birthdate.day, &birthdate.month, &birthdate.year);
  } while (validateBirthdate(birthdate, currentDate) != 0);

  int age = calculateAge(birthdate, currentDate);

  int id = generateId();

  printf("\n\nEmployee Details:\n-------------------------\n");
  printf("Employee ID: R%04d\n", id);
  printf("Name: %s\n", name);
  printf("Department: %s\n", department);
  printf("Age: %d\n", age);
}
