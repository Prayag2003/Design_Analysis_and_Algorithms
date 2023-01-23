#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 100000
int i, j;

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void reverse_array(int *arr)
{
    for (i = 0; i < N / 2; i++)
    {
        swap(&arr[i], &arr[N - i - 1]);
    }
}

bool isSorted(int *arr)
{
    for (i = 0; i < N - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            return false;
        }
        return true;
    }
}

void selection_sort(int *arr)
{
    int min_index;
    long long int swap_count = 0, comparisons = 0;

    for (i = 0; i < N - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
            comparisons++;
        }

        if (min_index != i)
        {
            swap( &arr[min_index], &arr[i] );
            swap_count++;
        }
    }
    printf("\nNo of Comparisons is %llu", comparisons);
    printf("\nNo of Swap Counts is %llu\n", swap_count);
}

void calculateTime(int *arr)
{
    clock_t time;
    time = clock();

    selection_sort(arr);

    time = clock() - time;
    double time_taken = ((double)time) / CLOCKS_PER_SEC;

    printf("The Time taken is equal to %.18lf seconds\n", time_taken);
}

int main()
{
    int arr[N];

    for (i = 0; i < N; i++)
    {
        arr[i] = rand();
    }

    //  ******************   A V E R A G E   C A S E    ****************

    printf("\nAverage Case");
    calculateTime(arr);

    //   *****************      B E S T    C A S E    *******************
    printf("\nBest Case");
    isSorted(arr) ? printf("\nThe Array is Sorted , All is Well\n") : printf("The Array is not Sorted :( \n");
    calculateTime(arr);
    printf("\n");

    //   *****************      W O R S T   C A S E     ********************

    printf("\nWorst Case");
    reverse_array(arr);
    calculateTime(arr);
    printf("\n");
}