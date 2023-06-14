#include <stdio.h>
#include <stdlib.h>

#define INITIAL_STUDENT_COUNT 10

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
  studentList->students = (Student *)malloc(sizeof(Student) * INITIAL_STUDENT_COUNT);
  studentList->studentCount = 0;
  studentList->studentsSize = INITIAL_STUDENT_COUNT;
}

void displayStudent(StudentList *studentList)
{
  for (size_t i = 0; i < studentList->studentCount; i++)
  {
    printf("Name: %s\n", studentList->students[i].name);
  }
}

void addStudent(StudentList *studentList)
{
  if (studentList->studentCount  == studentList->studentsSize)
  {
    studentList->studentsSize *= 2;
    studentList->students = (Student *)realloc(studentList->students, sizeof(Student) * studentList->studentsSize);

    if(studentList->students == NULL) {
      printf("Error allocating memory");
      exit(1);
    }
  }

  printf("Enter name: ");
  scanf("%s", studentList->students[studentList->studentCount].name);

  studentList->studentCount++;
}

int main()
{
  StudentList studentList;
  initializeStudentList(&studentList);
  displayStudent(&studentList);
  addStudent(&studentList);
  addStudent(&studentList);
  addStudent(&studentList);
  displayStudent(&studentList);
}
