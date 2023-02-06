#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 10000
#define ll long long int
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

// int partition(int *arr, int s, int e)
// {
//     // starting element of that array ( PIVOT )
//     int pivot = arr[s];

//     // counting numbers less than equal to pivot to allocate them to the left of the pivot
//     int cnt = 0;
//     int comp = 0;
//     for (int i = s + 1; i <= e; i++)
//     {
//         comp++;
//         if (arr[i] <= pivot)
//             cnt++;
//     }

//     // Finding the PivotIndex and replacing it with that element on it
//     int pivotIndex = s + cnt;
//     swap(&arr[s], &arr[pivotIndex]);

//     // Create 2 pointers for making partition
//     int i = s, j = e;
//     while (i < pivotIndex && j > pivotIndex)
//     {
//         while (arr[i] <= pivot)
//         {
//             i++;
//         }
//         while (arr[j] > pivot)
//         {
//             j--;
//         }
//         if (i < pivotIndex && j > pivotIndex)
//         {
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     return pivotIndex;
// }

int partition(int arr[], int start, int end)
{
    // considering the right most element  as the pivot ele
    int comparisons = 0;
    int pivot = arr[end];

    // element index for comparison
    int i = (start - 1);

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            comparisons++;
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Placing pivot at it correct position
    swap(&arr[i + 1], &arr[end]);

    // returning index for next pivot
    return i + 1;
}

void quickSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    // finding Partitioning Index
    int ind = partition(arr, s, e);

    // Recursive Call for left side
    quickSort(arr, s, ind - 1);
    quickSort(arr, ind + 1, e);
}

void calculateTime(int arr[], int start, int end)
{
    clock_t time;
    time = clock();

    quickSort(arr, 0, N - 1);

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

    printf("\nAverage Case\n");
    calculateTime(arr, 0, N - 1);

    //   *****************      B E S T    C A S E    *******************
    printf("\nBest Case\n");
    isSorted(arr) ? printf("\nThe Array is Sorted , All is Well\n") : printf("The Array is not Sorted :( \n");
    calculateTime(arr, 0, N - 1);
    printf("\n");

    //   *****************      W O R S T   C A S E     ********************

    printf("\nWorst Case\n");
    reverse_array(arr);
    calculateTime(arr, 0, N - 1);
    printf("\n");
}
