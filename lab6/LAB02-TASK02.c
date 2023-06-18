#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INITIAL_STUDENT_COUNT 10

// utility functions

int getInteger(char prompt[])
{
  double number;
  while (1)
  {
    printf("%s", prompt);
    int termCount = scanf("%lf", &number);
    while (getchar() != '\n')
      ;

    if (termCount == 0 || number - (int)number != 0.0)
    {
      printf("Please enter a valid integer input\n");
      continue;
    }

    // If no error is found
    return (int)number;
  }
}

double getDouble(char prompt[])
{
  double number;
  while (1)
  {
    printf("%s", prompt);
    int termCount = scanf("%lf", &number);
    while (getchar() != '\n')
      ;

    if (termCount == 0)
    {
      printf("Please enter a valid decimal input\n");
      continue;
    }

    // If no error is found
    return number;
  }
}

void getString(char str[], size_t size, char prompt[])
{
  char raw[256] = ""; // A raw input string with sufficiently large size, initialised to empty string.
  while (1)
  {
    printf("%s", prompt);
    scanf("%[^\n]%*c", raw);

    //  ^\n tells to take input until newline doesn't get encountered.
    //  Then, with %*c, it reads newline character and here used * indicates that this newline character is discarded.
    // reference: https://stackoverflow.com/questions/314401/how-to-read-a-line-from-the-console-in-c

    if (strlen(raw) > size)
    {
      printf("Please enter a string with less than %ld characters\n", size);
      continue;
    }

    strcpy(str, raw);
    return;
  };
}

void getName(char str[], size_t size)
{
  getString(str, size, "Name: ");
}

void getRollNumber(char str[], size_t size)
{
  getString(str, size, "Matric: ");
}

void getRollNumberWithPrompt(char str[], size_t size, char prompt[])
{
  getString(str, size, prompt);
}

void getGPA(float *gpa)
{
  *gpa = getDouble("GPA: ");
}

void getAge(int *age)
{
  *age = getInteger("Age: ");
}

// Important structures

typedef struct
{
  char name[256];
  char rollNumber[7]; // Assume roll number to be in the format of A000000
  unsigned int age;
  float gpa;
} Student;

typedef struct
{
  Student *students;
  size_t studentCount;
  size_t studentsSize;
} StudentList;

// Operation Functions

void initializeStudentList(StudentList *studentList)
{
  studentList->students = malloc(sizeof(Student) * INITIAL_STUDENT_COUNT);
  if (studentList->students == NULL)
  {
    printf("Error allocating memory");
    exit(1);
  }
  studentList->studentCount = 0;
  studentList->studentsSize = INITIAL_STUDENT_COUNT;
}

void displayStudent(StudentList *studentList)
{
  if (studentList->studentCount <= 0)
  {
    printf("No students found in record\n");
    return;
  }

  printf("Student Record\n");
  for (size_t i = 0; i < studentList->studentCount; i++)
  {
    printf("Name: %s\n", studentList->students[i].name);
    printf("Matric Number: %s\n", studentList->students[i].rollNumber);
    printf("Age: %d\n", studentList->students[i].age);
    printf("GPA: %.2f\n", studentList->students[i].gpa);
    printf("\n");
  }
}

void addStudent(StudentList *studentList)
{
  if (studentList->studentCount == studentList->studentsSize)
  {
    studentList->studentsSize *= 2;
    studentList->students = (Student *)realloc(studentList->students, sizeof(Student) * studentList->studentsSize);

    if (studentList->students == NULL)
    {
      printf("Error allocating memory");
      exit(1);
    }
  }

  printf("Enter student details:\n");
  Student newStudent;

  getName(newStudent.name, sizeof(newStudent.name));
  getRollNumber(newStudent.rollNumber, sizeof(newStudent.rollNumber));
  getAge(&newStudent.age);
  getGPA(&newStudent.gpa);

  studentList->students[studentList->studentCount] = newStudent;
  studentList->studentCount++;
}

void searchStudent(StudentList *studentList)
{
  char name[256];
  getString(name, sizeof(name), "Enter the name of the student to search:\n");
  printf("\n");
  for (int i = 0; i < studentList->studentCount; i++)
  {
    if (strcmp(studentList->students[i].name, name) == 0)
    {
      printf("Student found:\n");
      printf("Name: %s\n", studentList->students[i].name);
      printf("Matric Number: %s\n", studentList->students[i].rollNumber);
      printf("Age: %d\n", studentList->students[i].age);
      printf("GPA: %.2f\n", studentList->students[i].gpa);
      return;
    }
  }

  printf("No student with name, %s found in the record.\n", name);
}

void updateStudent(StudentList *studentList)
{
  char rollNumber[7];
  getString(rollNumber, sizeof(rollNumber), "Enter the matric number of the student to update: ");

  for (size_t i = 0; i < studentList->studentCount; i++)
  {
    if (strcmp(rollNumber, studentList->students[i].rollNumber) == 0)
    {
      printf("Enter updated details:\n");
      getName(studentList->students[i].name, sizeof(studentList->students[i].name));
      getRollNumber(studentList->students[i].rollNumber, sizeof(studentList->students[i].rollNumber));
      getAge(&studentList->students[i].age);
      getGPA(&studentList->students[i].gpa);

      printf("\nStudent details updated successfully!\n");

      return;
    }
  }

  // not found
  printf("No student with matric number, %s found in the record.\n", rollNumber);
}

void removeStudent(StudentList *studentList)
{
  char rollNumber[7];

  getString(rollNumber, sizeof(rollNumber), "Enter the matric number of the student to delete: ");

  for (size_t i = 0; i < studentList->studentCount; i++)
  {
    if (strcmp(rollNumber, studentList->students[i].rollNumber) == 0)
    {
      Student lastStudent = studentList->students[studentList->studentCount - 1];
      studentList->students[i] = lastStudent;
      studentList->studentCount--;

      // if current count is <= 1/4 of max size, allocate less memory
      if (studentList->studentCount * 4 < studentList->studentsSize)
      {
        printf("I'm being runnnnnnnnn");
        studentList->studentsSize /= 2;
        studentList->students = realloc(studentList->students, sizeof(Student) * studentList->studentsSize);
        if (studentList->students == NULL)
        {
          printf("Error allocating memory");
          exit(1);
        }
      }

      printf("\nStudent record deleted successfully!\n");
      return;
    }
  }

  printf("No student with matric number, %s found in the record.\n", rollNumber);
}

int main()
{
  StudentList studentList;
  initializeStudentList(&studentList);

  printf("Welcome to Student Record Management System\n\n");
  printf("Menu:\n\n");
  printf("1. Add a student\n");
  printf("2. Display all students\n");
  printf("3. Search for a student\n");
  printf("4. Update student details\n");
  printf("5. Delete a student record\n");
  printf("6. Exit\n\n");

  int choice;
  while (1)
  {
    choice = getInteger("Enter your choice: ");
    printf("\n");

    switch (choice)
    {
    case 1:
      addStudent(&studentList);
      break;

    case 2:
      displayStudent(&studentList);
      break;

    case 3:
      searchStudent(&studentList);
      break;

    case 4:
      updateStudent(&studentList);
      break;

    case 5:
      removeStudent(&studentList);
      break;

    case 6:
      exit(0);
      break;

    default:
      printf("Invalid choice.\n");
      break;
    }

    printf("\n");
  }
}
