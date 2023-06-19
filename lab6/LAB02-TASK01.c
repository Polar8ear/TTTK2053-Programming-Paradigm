#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// using a macro to define the maximum array size
// so it can be changed easily to generate different
// number of elements
#define ARRAY_SIZE 10

int calculateSum(int array_list[], int size);
int initialize_array(int array_list[], int size);
struct Maximum findMaximum(int array_list[], int size);
void reverseArray(int *array, int size);


struct Maximum
{
    int index;
    int max;
};

int main()
{
    int size = ARRAY_SIZE;
    int integer_array[ARRAY_SIZE];
    initialize_array(integer_array, size);

    printf("Original Array: ");
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", integer_array[i]);
    }
    printf("\n\n");

    int sum = calculateSum(integer_array, 10);
    printf("Sum of all elements: %d\n", sum);

    struct Maximum m1 = findMaximum(integer_array, size);
    printf("Maximum element: %d", m1.max);
    printf(", Index: %d", m1.index);

    printf("\n\n");
    reverseArray(integer_array, size);

    printf("Reversed Array: ");
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", integer_array[i]);
    }
    printf("\n");

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

struct Maximum findMaximum(int array_list[], int size)
{
    struct Maximum m1 = {0, INT_MIN};
    for (int i = 0; i < size; i++)
    {
        if (array_list[i] > m1.max)
        {
            m1.max = array_list[i];
            m1.index = i;
        }
    }

    return m1;
}

// void reverseArray(int array[], int size)
// {
//     //when an odd integer number divided by 2 in C will be rounded down
//     for (int i = 0; i < size / 2; i++)
//     {
//         // [0,1,2,3,4,5]
//         int temp = array[i];
//         // temp = 0
//         array[i] = array[size-i-1];
//         // [5,1,2,3,4,5]
//         array[size-i-1] = temp;
//         // [5,1,2,3,4,0]
//     }
// }

void reverseArray(int *array, int size)
{
    // when an odd integer number divided by 2 in C will be rounded down
    for (int i = 0; i < size / 2; i++)
    {
        // [0,1,2,3,4,5]
        int temp = *(array + i);
        // printf("%d ", *(array +  i));
        // // temp = 0
        *(array + i) = *(array + (size - i - 1));
        // // [5,1,2,3,4,5]
        *(array + (size - i - 1)) = temp;
        // // [5,1,2,3,4,0]
    }
}
