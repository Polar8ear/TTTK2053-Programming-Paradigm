#include <stdio.h>

int main()
{
    double score;
    printf("Enter your score: ");
    int termCount = scanf("%lf", &score);

    // Test Case 1: Handle non-numerical
    if (termCount == 0)
    {
        printf("Please enter a valid numerical input");
        return 1;
    }

    printf("Score: %.1lf\n", score);

    // Determine the grade of the score
    if (score >= 90.0 && score <= 100.0)
    {
        printf("Grade: A+");
    }
    else if (score >= 80 && score < 90)
    {
        printf("Grade: A");
    }
    else if (score >= 70 && score < 80)
    {
        printf("Grade: B+");
    }
    else if (score >= 60 && score < 70)
    {
        printf("Grade: B");
    }
    else if (score >= 50 && score < 60)
    {
        printf("Grade: C+");
    }
    else if (score >= 40 && score < 50)
    {
        printf("Grade: C");
    }
    else if (score >= 30 && score < 40)
    {
        printf("Grade: D");
    }
    else if (score >= 0 && score <= 30)
    {
        printf("Grade: F");
    }
    else
    {
        // Test Case 2: Handle >100 case
        // Test Case 3: Handle <0 case
        printf("Value out of valid range.\nPlease input a number within 0 and 100");
    }
    return 0;
}