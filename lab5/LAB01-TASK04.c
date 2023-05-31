#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int getNumber()
{

    double number;
    int termCount = scanf("%lf", &number);
    while (getchar() != '\n')
        ;

    while (1)
    {
        // Handle Test Case 1: Non-numerical input
        // Handle Test Case 2: Input not within range
        // Handle Test Case 3: Double/Float input

        if (termCount == 0)
        {
            // Test Case 1
            printf("Please enter a valid numerical input\n");
            printf("Guess a number between 1 and 100:");
        }
        else if (number <= 1 || number >= 100)
        {
            // Test Case 2
            printf("Please enter a value which is between 1 and 100\n");
            printf("Guess a number between 1 and 100:");
        }
        else if (number - (int)number != 0)
        {
            // Test Case 3
            printf("Please enter an integer value\n");
            printf("Guess a number between 1 and 100:");
        }
        else
        {
            // If no error is found
            return (int)number;
        }

        termCount = scanf("%lf", &number);
        while (getchar() != '\n')
            ;
    }
}

int main()
{
    int guess; // User's Guess
    srand(time(0));
    int target = (rand() % 100 + 1); // get random number between 1 to 100
    printf("Welcome to the Number Guessing Game!\n");
    printf("Guess a number between 1 and 100:");
    guess = getNumber();

    while (guess != target)
    {

        if (guess < target)
        {
            printf("Too low! Guess a higher number: ");
        }
        else
        {
            printf("Too high! Guess a lower number: ");
        }
        guess = getNumber();
    };

    printf("Congratulations! You guessed the number %d correctly.", target);
}
