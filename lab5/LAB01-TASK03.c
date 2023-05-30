#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("Enter a positive integer: ");

    int num;
    int termCount = scanf("%d", &num);

    if (termCount != 1)
    {
        printf("Please enter a valid postive integer.");
        return 1;
    }

    if (num < 0)
    {
        printf("Please enter a postiive integer");
        return 1;
    }

    if(num > 20) {
        printf("Warning, enter a value larger than 20 will provide an inaccurate answer due to overflow of variable.");
    }

    unsigned long long factorial = 1;
    for (int i = 1; i <= num; i++)
    {
        factorial *= i;
    }

    printf("Number: %d\n", num);
    printf("Factorial: %lld\n", factorial);

    return 0;
}
