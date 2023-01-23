#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#define N 100

int i, j, key;

void reverse(int *arr)
{
    for (i = 0; i < N / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[N - i - 1];
        arr[N - i - 1] = temp;
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

void merge_sort( int *arr )
{
    
}

void calculateTime(int *arr)
{
    clock_t time;
    time = clock();

    insertion_sort(arr);

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

    calculateTime(arr);
    isSorted(arr) ? printf("\nThe Array is Sorted , All is Well\n ") : printf("The Array is not Sorted :( ");

    //   *****************      B E S T    C A S E    *******************

    calculateTime(arr);

    //   *****************      W O R S T   C A S E     ********************

    reverse(arr);
    calculateTime(arr);
}