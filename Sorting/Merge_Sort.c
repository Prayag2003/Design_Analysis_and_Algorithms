#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 100000
#define ll long long int

ll comparisons;
ll i, j;

void swap(ll *a, ll *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void reverse_array(ll *arr)
{
    for (i = 0; i < N / 2; i++)
    {
        swap(&arr[i], &arr[N - i - 1]);
    }
}

bool isSorted(ll *arr)
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

void merge(ll *arr, ll start, ll end)
{
    ll mid = start + (end - start) / 2;
    ll len1 = mid - start + 1;
    ll len2 = end - mid;

    ll arr1[len1];
    ll arr2[len2];

    ll mainArrayIndex = start;

    for (i = 0; i < len1; i++)
    {
        arr1[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (i = 0; i < len2; i++)
    {
        arr2[i] = arr[mainArrayIndex++];
    }

    int ind1 = 0, ind2 = 0;
    mainArrayIndex = start;

    while (ind1 < len1 && ind2 < len2)
    {
        if (arr1[ind1] < arr2[ind2])
        {
            comparisons++;
            arr[mainArrayIndex++] = arr1[ind1++];
        }
        else
        {
            arr[mainArrayIndex++] = arr2[ind2++];
        }
    }
    while (len1 > ind1)
    {
        comparisons++;
        arr[mainArrayIndex++] = arr1[ind1++];
    }

    while (len2 > ind2)
    {
        comparisons++;
        arr[mainArrayIndex++] = arr2[ind2++];
    }
}

void mergeSort(ll *arr, ll start, ll end)
{

    if (start >= end)
    {
        return;
    }
    ll mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);

    mergeSort(arr, mid + 1, end);

    merge(arr, start, end);
}

void calculateTime(ll *arr, ll start, ll end)
{
    clock_t time;
    time = clock();

    mergeSort(arr, start, end);

    time = clock() - time;
    double time_taken = ((double)time) / CLOCKS_PER_SEC;

    printf("The Time taken is equal to %.18lf seconds\n", time_taken);
}

int main()
{
    ll arr[N];

    for (i = 0; i < N; i++)
    {
        arr[i] = rand();
    }

    //  ******************   A V E R A G E   C A S E    ****************

    printf("\nAverage Case\n");
    calculateTime(arr, 0, N - 1);
    printf("The Number of Comparisons are %d\n" , comparisons);

    //   *****************      B E S T    C A S E    *******************
    printf("\nBest Case\n");
    isSorted(arr) ? printf("\nThe Array is Sorted , All is Well\n") : printf("The Array is not Sorted :( \n");
    calculateTime(arr, 0, N - 1);
    printf("The Number of Comparisons are %d\n" , comparisons);
    printf("\n");

    //   *****************      W O R S T   C A S E     ********************

    printf("\nWorst Case\n");
    reverse_array(arr);
    calculateTime(arr, 0, N - 1);
    printf("The Number of Comparisons are %d\n" , comparisons);
    printf("\n");
}
