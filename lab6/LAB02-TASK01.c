#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int calculateSum(int array_list[], int size);
int initialize_array(int array_list[], int size);
int findMaximum(int array_list[], int size, int *max_index);

int main()
{
    int max_index;
    int sum;
    int size = 10;
    int integer_array[10];
    initialize_array(integer_array, size);

    printf("Original Array: ");
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", integer_array[i]);
    }
    printf("\n");

    sum = calculateSum(integer_array, 10);
    printf("Sum of all elements: %d\n", sum);

    int max = findMaximum(integer_array, size, max_index);
    printf("Maximum element: %d", max);
    printf(",Index: %d", max_index);
    return 0;
}

int initialize_array(int array_list[], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        int random_number = rand();
        array_list[i] = random_number;
    }

    return 0;
}

int calculateSum(int array_list[], int size)
{
    int sum;
    for (int i = 0; i < size; i++)
    {
        sum += array_list[i];
    }
    return sum;
}

int findMaximum(int array_list[], int size, int *max_index)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (array_list[i] > max)
        {
            max = array_list[i];
            max_index = i;
        }
    }

    return max;
}