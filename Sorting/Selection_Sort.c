#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int i, j, min_index;

void swapp(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
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

void selection_sort(int *arr)
{
    long long int cnt = 0;
    for (i = 0; i < N - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        cnt++;
        swapp(&arr[min_index], &arr[i]);
    }
    printf("\nNo of Counts is %lu\n", cnt);
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

    calculateTime(arr);
    isSorted(arr) ? printf("\nThe Array is Sorted , All is Well\n ") : printf("The Array is not Sorted :( ");

    //   *****************      B E S T    C A S E    *******************

    calculateTime(arr);

    //   *****************      W O R S T   C A S E     ********************

    reverse(arr);
    calculateTime(arr);
}