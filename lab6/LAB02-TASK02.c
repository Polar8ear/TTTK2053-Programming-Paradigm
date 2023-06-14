#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_STUDENT_COUNT 10

int getInteger()
{

  double number;
  while (1)
  {
    int termCount = scanf("%lf", &number);
    while (getchar() != '\n')
      ;
    if (termCount == 0)
    {
      printf("Please enter a valid integer input\n");
    }
    else if (number - (int)number != 0)
    {
      printf("Please enter an integer value\n");
    }
    else
    {
      // If no error is found
      return (int)number;
    }
  }
}

double getDouble()
{
  double number;
  while (1)
  {
    int termCount = scanf("%lf", &number);
    while (getchar() != '\n')
      ;

    if (termCount == 0)
    {
      printf("Please enter a valid decimal input\n");
    }
    else
    {
      // If no error is found
      return number;
    }
  }
}

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

  // printf("Name: ");
  // fgets(newStudent.name, sizeof(newStudent.name), stdin);
  // newStudent.name[strlen(newStudent.name) - 1] = '\0';

  printf("Matric Number: ");
  fgets(newStudent.rollNumber, sizeof(newStudent.rollNumber) + 1, stdin);
  newStudent.rollNumber[strlen(newStudent.rollNumber)] = '\0';

  // printf("Age: ");
  // newStudent.age = getInteger();

  // printf("GPA: ");
  // newStudent.gpa = getDouble();

  studentList->students[studentList->studentCount] = newStudent;
  studentList->studentCount++;
}

void updateStudent(StudentList *studentList)
{
  Student draftStudent;

  printf("Enter the matric number of the student to update: ");
  scanf("%s", draftStudent.rollNumber);

  for (size_t i = 0; i < studentList->studentCount; i++)
  {
    printf("%s", draftStudent.rollNumber);
    printf("%s", studentList->students[i].rollNumber);

    // if (strcmp(draftStudent.rollNumber, studentList->students[i].rollNumber) == 0)
    if(1)
    {
      printf("Enter updated details: \n");
      printf("Name: \n");
      fgets(studentList->students[i].name, sizeof(studentList->students[i].name), stdin);
      studentList->students[i].name[strlen(studentList->students[i].name) - 1] = '\0';

      printf("Matric Number: \n");
      fgets(studentList->students[i].rollNumber, sizeof(studentList->students[i].rollNumber), stdin);
      studentList->students[i].rollNumber[strlen(studentList->students[i].rollNumber) - 1] = '\0';

      printf("Age: \n");
      studentList->students[i].age = getInteger();

      printf("GPA: \n");
      studentList->students[i].gpa = getDouble();

      // print update successful

      return;
    }
  }

  // not found
}

int main()
{
  StudentList studentList;

  initializeStudentList(&studentList);
  displayStudent(&studentList);
  addStudent(&studentList);
  addStudent(&studentList);
  // addStudent(&studentList);
  updateStudent(&studentList);
  displayStudent(&studentList);
}
